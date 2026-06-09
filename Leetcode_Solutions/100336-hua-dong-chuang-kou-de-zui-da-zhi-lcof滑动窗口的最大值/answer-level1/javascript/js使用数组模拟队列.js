### 解题思路
可以使用数组模拟队列，窗口每次滑动，其实要做的就是，删除队列头和添加队列尾。
1.找到窗口从头滑到尾需要滑动的次数为： nums.length - k + 1
2.初始化队列
3.每次滑动的时候，找到当前窗口的最大值保存到 res 数组，然后执行 删除队列头元素、在队列尾添加下一元素的操作

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {

    if (nums.length == 0 || k > nums.length) return []

    var index = k
    var len = nums.length - k + 1
    var stack = [], res = []

    for (var j = 0; j < k; j++) {
        stack.push(nums[j])
    }

    for (i = 0; i < len; i++) {
        if (i !== 0) {
            stack.shift()
            stack.push(nums[index])
            index++
        }
        res.push(Math.max.apply(null, stack))
    }

    return res
};
```