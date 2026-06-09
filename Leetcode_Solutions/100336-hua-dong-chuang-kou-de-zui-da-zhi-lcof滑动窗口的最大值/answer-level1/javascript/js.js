### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function (nums, k) {
    // 单调下降的队列，最大值就是对头元素
    let res = [];//保存答案
    let queue = [];//要维护的队列,队列中存的数组下表，不是数组元素
    let len = nums.length;
    for (let i = 0; i < len; i++) {
        while (queue.length && queue[0] <= i - k) queue.shift();//超出了k的窗口长度，弹出对头元素
        //进来的元素>=队尾元素，就将从队中元素弹出，他因为他永远不可能是答案
        while (queue.length && nums[queue[queue.length - 1]] <= nums[i]) queue.pop();

        queue.push(i);
        // 从下标是k-1的时候就开始插入
        if (i >= k - 1) res.push(nums[queue[0]]);
    }
    return res;
};
```