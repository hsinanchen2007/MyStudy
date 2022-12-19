### 解题思路
经典模版

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let l = 0;
    let r = nums.length-1;
    const result =[]
    while(l<r){
        let sum = nums[l] + nums[r];
        if(sum == target){
            result.push(nums[l])
            result.push(nums[r])
            break;
        }else if(sum < target){
            l++
        }else{
            r--
        }
    }
    return result
};
```