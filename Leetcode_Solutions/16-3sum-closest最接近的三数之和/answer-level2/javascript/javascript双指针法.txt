### 解题思路
假如使用三层for循环，时间复杂度将为O(n^3)。因此，只使用一层外部循环，循环内部使用双指针法。从而减小时间复杂度。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    nums.sort((a,b) => a - b);
    let threeSumCLosest = nums[0] + nums[1] + nums[2];
    for(let i = 0;i < nums.length;i ++) {
       let j = i + 1;
       let k = nums.length - 1;
        while(j < k) {
            let sum = nums[i] + nums[j] + nums[k] ;
            threeSumCLosest = Math.abs(sum - target) < Math.abs(threeSumCLosest - target)? sum : threeSumCLosest;
            if(sum - target > 0) {
                k --;
            } else if(sum - target < 0) {
                j ++;
            } else {
                return threeSumCLosest;
            }
        }
       
    }
    return threeSumCLosest;
};
```