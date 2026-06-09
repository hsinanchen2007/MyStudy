### 解题思路
hhhh,总共才八个题解。

那我怎么搞内存消耗都会击败100%。

反正都不会有人看，那么看的人看代码就好了。

> 个人给我感觉做这道题像是在玩游戏

### 代码

```javascript
/**
 * @param {number[][]} ghosts
 * @param {number[]} target
 * @return {boolean}
 */
var escapeGhosts = function(ghosts, target) {
	if (target[0] == 0 && target[1] == 0) return true; // fuck
	let pos = [0, 0]; // pacman's position
	let isGhostAtEnd = () => ghosts.filter(s => s.toString() == target.toString()).length > 0;
	let isCatched = () => ghosts.filter(s => s.toString() == pos.toString()).length > 0;
	let isAtEnd = () => pos.toString() == target.toString();

	let arraySum = (ary1, ary2) => [ary1[0]+ary2[0], ary1[1]+ary2[1]];
	let computeAction = (pos, target) => (pos[0] == target[0] && pos[1] == target[1]) ? pos :
	 (pos[0] != target[0] ? (target[0] - pos[0] > 0 ? [1,0] : [-1,0]) : (target[1] - pos[1] > 0 ? [0,1] : [0,-1]));

	while (true) {
		// pacman walk
		pos = arraySum(pos, computeAction(pos, target));
		// ghosts walk
		ghosts.forEach((ghost, index) => {ghosts[index] = arraySum(ghost, computeAction(ghost, target))});

		if (isCatched()||isGhostAtEnd()) return false;
		else if (isAtEnd()) return true;
	}
};

```