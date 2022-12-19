### 代码

```javascript
var twoSum = function(nums, target) {
    let low = 0,
        high = nums.length - 1;
    while(low < high){
        if(nums[low] + nums[high] < target){
            low++
        }else if(nums[low] + nums[high] > target){
            high--
        }else{
            return [nums[low], nums[high]]
        }
    }
    return -1
};
```