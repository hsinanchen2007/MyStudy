### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let count = 0
    for(let i=0; i<nums.length; i++){
        if(nums[i].toString().length % 2 == 0) count+=1
    }
    return count
};
```