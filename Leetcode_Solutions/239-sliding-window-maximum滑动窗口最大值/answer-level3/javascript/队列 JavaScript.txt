### 解题思路
总感觉哪里不太对劲...
![image.png](https://pic.leetcode-cn.com/9252926ac45e27f21bb6ffcd7f3e767fed99968391eacb4693994388ec06f5ba-image.png)

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