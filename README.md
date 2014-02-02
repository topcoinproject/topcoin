TopCoin (TOP) - TopCoin is a new generation of scrypt coin that is descendant of Litecoin. Like Litecoin it uses scrypt as a proof of work scheme.

TopCoin uses faster distribution scheme. Initially it provides 1 million coins per block. The block payout halves every two days or 5760 blocks. The minimum payout of each block will be 1 coin. And when reaching the minimum payout, the system will randomly generate certain bonus blocks:
	- each hour there will be a 10X payout block
	- each day there will be a 100X payout block 

Other Specifications:
	- 30 seconds block target
	- Difference retargets each block
	- Total coins will be 12 billion coins
	- 4 confirmations for transaction, thus 2 mins fast transaction time
	- 50 confirmations for minted blocks

	- The default ports are 18381 (Connect) and 18382 (RPC)



Development process
===================

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
official, stable release versions of TopCoin.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'. 
