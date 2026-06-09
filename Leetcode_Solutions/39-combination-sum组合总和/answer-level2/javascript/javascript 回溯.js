### 解题思路
回溯相关问题：
[39. 组合总和](https://leetcode-cn.com/problems/combination-sum/solution/javascript-hui-su-by-woodyjang-2-2/)
[40. 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/solution/javascript-hui-su-by-woodyjang-2-3/)
[46. 全排列](https://leetcode-cn.com/problems/permutations/)
[51. N皇后](https://leetcode-cn.com/problems/n-queens/)
[52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)
[77. 组合](https://leetcode-cn.com/problems/combinations/)
[78. 子集](https://leetcode-cn.com/problems/subsets/)
[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let res = [],tmpPath = []
    let backtrack = (tmpPath,start) => {
      let sum = tmpPath.reduce((pre,cur) => pre + cur,0)
      if(sum === target){
        res.push(tmpPath)
        return
      } else if (sum > target){
        return
      }
      for(let i = start;i<candidates.length;i++){
        tmpPath.push(candidates[i])
        backtrack(tmpPath.slice(),i)
        tmpPath.pop()
      }
    }
    backtrack(tmpPath,0)
    return res
};
```