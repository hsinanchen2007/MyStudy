### 解题思路
![image.png](https://pic.leetcode-cn.com/f6408b18bc252d4212bfab9e87636a258fd999d761a1146d8e12c30ae679af80-image.png)

 - 中心思想就是：0往前放，2往后放；
 - 使用三个指针，存放0的指针start，存放1的指针end，移动指针cur；
 - 注意结束条件不是 cur < length; 而是 cur <= end;
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */

var sortColors = function(nums) {
    const length = nums.length - 1;
    let start = 0;
    let end = length;
    let cur = 0;
    let cval;
    function swap(start, end) {
        const temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp; 
    }
    while(cur <= end) {
        cval = nums[cur];
        // 当前数为0，就往前放，放了之后0指针自然就+1;
        // 但还需要cur也加1，因为cur已经为0了，交换后，不可能变大，所以curr也得往前
        if (cval === 0) {
            swap(cur, start);
            start++;
            cur++;
        }
        // 这里start不能++，因为后面交换回来的，有可能是0，所以还得经下一轮比较判断，再决定是否+1；
        if(cval === 2) {
            swap(cur, end);
            end--;
        } 
        // 为1，就是特殊情况，暂时不动，继续往前查找
        if (cval === 1) {
            cur++
        }
    }
};
```