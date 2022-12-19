### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let arr = [];
    if(nums.length==1)
        return nums[0];
    for(let i =0;i<nums.length;i++){
        if(arr[nums[i]]===undefined){
            arr[nums[i]]=0;
        }else{
            arr[nums[i]]+=1;
            if(arr[nums[i]]+1>nums.length/2)
            return nums[i];
        }
    }
};
```