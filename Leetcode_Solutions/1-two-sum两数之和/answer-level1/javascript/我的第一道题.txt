### 解题思路


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let a,b;
    for(let i=0;i<nums.length;i++){
        for(let j=1;j<nums.length;j++){
            i==j?j++:''
            if(nums[i]+nums[j]==target){
                return [i,j]
            }
        }
    }
};
```