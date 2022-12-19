### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for(let i=1;i< nums.length;i++){
        if(nums[i] === nums[i-1]){
            nums.splice(i-1,1);
            i --;
        }
    }
    return nums.length;
};
```