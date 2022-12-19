如图：
```
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    for (let i = 0; i <= nums.length; i++) {
        if (nums[i] !== i) return i;
    }
};
```
![image.png](https://pic.leetcode-cn.com/03c5f6a6d923574426a7aa9ca117751cea7a9ad9380d1ec1fb0974d08d01c928-image.png)
