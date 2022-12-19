荷兰三色问题解
```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let p0 = 0
    let cur = 0;
    let p2 = nums.length - 1;
    while(cur <= p2) {
        if(nums[cur] === 0) {
            [nums[cur],nums[p0]] = [nums[p0],nums[cur]] //这种写法逼格比较高 
            // swap(nums,cur,p0);// 这种写法也行
            cur++;
            p0++;
        } else if(nums[cur] === 2) {
            [nums[cur],nums[p2]] = [nums[p2],nums[cur]]
            // swap(nums,cur,p2);
            p2--;
        } else {
            cur++;
        }
    }
};
const swap = function(nums,a,b) {
    let temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
```