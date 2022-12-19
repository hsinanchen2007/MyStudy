### 解题思路
创建队列 如果下一位元素比队列最大值 queue[0] 大, 清空队列，让下一个元素成为 queue[0]。否则往后面push元素。当队列长度超过k时，剔除队列第一个元素，是队列剩下元素最大值成为 queue[0]

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    let queue = []
    let res = []
    let i = 0

    while(i < nums.length) {
        let first
        if(queue.length == 0) {
            first = nums[0]
            queue.push(nums[0]) 
        } else if (nums[i] > queue[0]){
            queue.splice(0, queue.length)
            queue.push(nums[i])
        } else {
            queue.push(nums[i])
        }
        // let first = queue.length == 0 ? nums[0] : 
        if(queue.length > k) {
            queue.shift()
            queue[0] = Math.max(...queue)
        }
        res.push(queue[0])
        i++
    }
    res.splice(0, k - 1)
    return res
};
```