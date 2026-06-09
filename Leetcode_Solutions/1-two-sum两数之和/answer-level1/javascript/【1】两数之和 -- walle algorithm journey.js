### 解题思路
解题思路：
 利用两次循环，拿出数组的一项，和数组的其余项求和，再和目标值对比
 个人感受是比较通俗的解法，肯定也不是最优答案
 需要花时间了解一下时间复杂度，空间复杂度，找到性能最好的解法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    if(nums.length){
        for(var i = 0; i < nums.length; i++){
            for(var j = i+1; j<nums.length; j++){
                if(nums[i] + nums[j] == target){
                    return [i,j]
                }
            }
        }
    }
};
```