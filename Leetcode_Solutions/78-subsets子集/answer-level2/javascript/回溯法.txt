### 解题思路
回溯法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let output = []
    
    function backtrack(i, tmpPath) {
        
        output.push(tmpPath)

        if(i > nums.length) return
        for(let j = i; j < nums.length; j++){
            backtrack(j + 1, tmpPath.concat([nums[j]]))
        }
    }
    backtrack(0, [])
    return output
};
```