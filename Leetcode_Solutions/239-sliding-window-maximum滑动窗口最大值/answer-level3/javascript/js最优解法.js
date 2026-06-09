### 解题思路

- 性能：
![image.png](https://pic.leetcode-cn.com/b2d23231d1f1f28ca5249df2998ea45a5c2ae2b4e7caf0c49f0b4de6ea43f497-image.png)
- `window`数组保存各个需要保留的元素的下标（要判断队伍头的值是否在窗口范围内，由数组下标取值很方便，而由值取数组下标不是很方便）
- 窗口移动，检查队首元素是否在窗口范围内，如果不在就滚出窗口
- 新元素进来之前，从队尾开始检查是否有比新元素小的值，有就删掉该元素在窗口数组的下标索引，因为不再需要它了
- 把新元素的下标保存到窗口数组里
- 这样就能保证，新元素进来之后，最左边的下标对应的值一定是整个窗口最大的

### 代码

```javascript
var maxSlidingWindow = function(nums, k) {
    let len = nums.length, window = [], result = []
    if (nums.length === 0) {
        return []
    }
    for (let i = 0; i < len; i++) {
        if (i >= window[0] + k) {
            window.shift()
        }
        while (nums[window[window.length - 1]] < nums[i]) {
            window.pop()
        }
        window.push(i)
        if (i >= k - 1) {
            result.push(nums[window[0]])
        }
    }
    return result
}
```