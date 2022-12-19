### 解题思路
javascript本题解法十分简单，因为是有序数组，故单一元素必然出现在奇数位，若nums[i] == nums[i+1]则表示不是单一元素，i+2

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
 for(i=0;i<nums.length;i++){
     if(nums[i] == nums[i+1]){
         i++
     }else{
         return nums[i]
     }
 }
};
```