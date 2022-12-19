### 解题思路
双指针，遍历数组内不为零的数，再遍历这个数之前有没有零，如果有则交换位置，将零逐个移动到最后。空间复杂度O(1),时间复杂度较高。有待优化。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let n = nums.length;
    for (let i=0; i<n; i++){
        if (nums[i] != 0){
            for (let j=0; j<i; j++){
                if (nums[j] === 0){
                    nums[j] = nums[i];
                    nums[i] = 0; 
                }
            }
        }
    }
};
```