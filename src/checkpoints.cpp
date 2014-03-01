// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2014 TopCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     0, uint256("0x8a1526dbe6de0928716c2dd2edb7a49c974bbd24fb89b6e76333561db37fa82e"))
            ( 10000, uint256("0x8e82cbd21ad7382c2937957f30003740b687386bd1091059904e91dc2c1c1b30"))
            ( 30000, uint256("0xcbee0b14f043d2e81f99670d13877b8396c086a2bdd77c87aad3df88f9d4513b"))
            ( 50000, uint256("0xd6dd08bd0bb939b60e978cf029898e923bd242798d00db886121326ab6cd30dd"))
            ( 70000, uint256("0xce840ded1b458df499222bcbeb5ebe55e3209baa484009040c6162790ca15b22"))
            ( 76500, uint256("0x99120731392f43022e38ebfc3eeada2883d9436b944709716cd2147e49077f32"))
			;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;
	
        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
		
        return NULL;
    }
}
