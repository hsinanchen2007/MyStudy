### 解题思路

     * 思考：1 ≤ a[i] ≤ n
     * 不用任何额外空间，利用数组索引构造隐形map 
     * 遍历数组，下标为abs(nums[i]) -1的值取反（-1是为了防止访问数组越界：a[i] ≤ n）
     * 如果遍历到的 下标为abs(nums[i]) -1的值 为负，说明abs(nums[i])出现了两次

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let result = []
    for(let i = 0; i < nums.length;i++){
        if(nums[Math.abs(nums[i])-1] > 0)
            nums[Math.abs(nums[i])-1] *= -1
        else
            result.push(Math.abs(nums[i]))
    }
    return result
};
```