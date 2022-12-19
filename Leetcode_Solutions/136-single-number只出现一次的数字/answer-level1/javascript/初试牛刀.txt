### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let arr=[];
    for(let i=0;i<nums.length; i++){
        if(arr.indexOf(nums[i]) == -1){
            arr[arr.length] = nums[i]
        }else{
            let x = arr.indexOf(nums[i])
            arr.splice(x,1)
        }
    
    }
    return arr[0]
};
```