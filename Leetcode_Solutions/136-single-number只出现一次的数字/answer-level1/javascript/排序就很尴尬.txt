### 解题思路
排序然后用find找，效率太低了...

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    return nums.sort((a,b)=>a-b).find((item,index)=>(item !== nums[index - 1] && item !== nums[index + 1]))
};
```