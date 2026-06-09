### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    const minums = nums.sort((a, b) => a - b).shift()
    console.log(minums)
    let moves = 0
    for(let i = 0; i < nums.length; i ++) {
        moves += Math.abs(nums[i] - minums)
    }
    return moves
};
```