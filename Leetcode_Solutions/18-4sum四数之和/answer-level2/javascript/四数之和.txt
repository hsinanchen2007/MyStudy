参考之前的三数之和、双循环加双指针
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    if(!nums || nums.length < 4) return [];
    let ans = [];
    let len = nums.length;
    nums.sort((a,b) => a - b);
    for(let i = 0 ; i < len - 3; i++) {
        if(i > 0 && nums[i] === nums[i - 1]) continue;
        if((nums[i] + nums[i+1] + nums[i+2] + nums[i+3]) > target) break;
        for(let j = i+1; j < len-2; j++) {
            if(j > i+1 && nums[j] === nums[j-1]) continue;
            let l = j + 1;
            let r = len - 1;
            while(l < r) {
                const sum = nums[i] + nums[j] + nums[l] + nums[r];
                if(sum === target) {
                    ans.push([nums[i] ,nums[j] ,nums[l] ,nums[r]]);
                    while(l < r && nums[l] === nums[l+1]) l++;
                    while(l < r && nums[r] === nums[r-1]) r--;
                    l++;
                    r--;
                } else if(sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    }
    return ans;
};
```