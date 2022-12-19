### 解题思路
此处撰写解题思路
时间复杂度有点高
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    for(let i=0;i<k;i++){
        nums.unshift(nums.pop())
    }
};
```