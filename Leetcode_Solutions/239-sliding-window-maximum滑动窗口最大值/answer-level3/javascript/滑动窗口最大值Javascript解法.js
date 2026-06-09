直接滑动窗口~
```
var maxSlidingWindow = function(nums, k) {
    let len = nums.length;
    if(len*k == 0) return [];
    if (k == 1) return nums;
    let queue = nums.slice(0,k);
    let cur = k-1;
    let target = [];
    while(cur<len){
        let max = Math.max.apply(Math,queue);
        target.push(max);
        cur++;
        queue.push(nums[cur]);
        queue.shift();
    }
    return target;
};
```
