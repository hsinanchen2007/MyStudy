### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let markOrder = "a";
    let markIndex= 0;
    let lengthNums = nums.length;
    nums.forEach((item,index)=>{
       
        if(item!=markOrder){
            markOrder = item;
            nums[markIndex] = markOrder;
            markIndex = markIndex+1;
        }
    })
    nums = nums.splice(markIndex)
};
```