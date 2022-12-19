### 代码
```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
    var l = 0, r = nums.length - 1;
    while(l < r){
        if(nums[l]%2 == 0 && nums[r]%2 == 1){
            var tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
        }
        if(nums[l]%2 == 1) l++;
        if(nums[r]%2 == 0) r--;
    }
    return nums;
};
```