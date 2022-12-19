### 解题思路
深度优先遍历 如果先转string 性能应该不会那么差

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let ans = []
    function dfs (nums, arr) {
        if(nums.length <= 0) ans.push(arr)
        for(let i in nums){
            let newNums =  Object.assign([], nums)
            let newArr = Object.assign([], arr)
            newArr.push(newNums.splice(i, 1))
            dfs(newNums, newArr)
        }
    }
    dfs(nums, [])
    return ans
}
```