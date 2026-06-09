### 解题思路
暴力暴力

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
let twoSum = (nums,target)=>{
   if(nums.length<2) return 0;
    for(var i = 0 ; i < nums.length ; i++){
        for(var j = 0 ; j < nums.length ; j++){
            if(nums[i]+nums[j] == target&&i!=j){                       
                return [i,j];
            }                   
        }
    }          
};
```