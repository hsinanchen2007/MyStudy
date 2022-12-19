### 解题思路
![image.png](https://pic.leetcode-cn.com/06806aec423137ece1cb643cb6e5d3b1e3b6f6a929a8c54f51aeade0072fe2d9-image.png)

用j来记录遇到的0的数量
若是不为0的数字前面有j个0（j>0），那么将那个不为0的数字与第一个0的位置交换

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let j =0;
    for(let i=0; i<nums.length; i++){
        if(nums[i] ==0){
            j++;
            continue;
        };

        if(j>0){ // 若是j不为0的时候，说明前面没有0不需要做移动，增加这个判断效率会高很多
            let tmp = nums[i];
            nums[i] = nums[i-j];
            nums[i-j] = tmp;
        }
    }
};
```