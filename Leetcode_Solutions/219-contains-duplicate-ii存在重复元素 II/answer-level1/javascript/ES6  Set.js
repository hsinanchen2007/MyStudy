### 解题思路

始终维持一个大小为k的滑动窗口，如果存在相同元素，则返回true，遍历完毕也没发现相同元素，返回false

### 代码

```javascript
var containsNearbyDuplicate = function(nums, k) {
    const set = new Set()
    for (let i = 0; i < nums.length; i++) {
        if (set.has(nums[i])) return true
        set.add(nums[i])
        if (set.size > k) {
            set.delete(nums[i - k])
        }
    }
    return false
};
```
最好情况：
时间复杂度：O(k)
空间复杂度：O(k)
最坏情况：
时间复杂度：O(n)
空间复杂度：O(n)