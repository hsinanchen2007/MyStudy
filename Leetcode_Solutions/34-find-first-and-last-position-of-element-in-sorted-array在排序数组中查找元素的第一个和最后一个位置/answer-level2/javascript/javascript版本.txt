思路:  二分查找

![屏幕快照 2020-01-04 20.15.46.png](https://pic.leetcode-cn.com/6452439e77a12e1a7e117ef9a52dad2c6a329229fe8a05d1c23d52a47fa86363-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-04%2020.15.46.png)



```
var searchRange = function(nums, target) {
    if (nums.length === 0) return [-1,-1];
    if (nums.length === 1) return nums[0] === target ? [0,0] : [-1,-1];
    let start = 0, end = nums.length - 1, mid = 0;
    while (start <= end) {
        mid = Math.ceil((start + end) / 2);
        if (nums[mid] === target) {
            start = end = mid;
            while (nums[start] === target) {
                start--;
            }
            while (nums[end] === target) {
                end++;
            }
            return [start+1, end-1]
        };
        if (start === end) return [-1, -1];
        if (nums[mid] > target) end = mid -1;
        else start = mid;
    }
    return [-1, -1]
};
```
