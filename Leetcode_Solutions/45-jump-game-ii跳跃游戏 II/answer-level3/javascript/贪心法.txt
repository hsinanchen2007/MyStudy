### 解题思路
使用贪心算法，每次更新能跳得最远的位置。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let res = 0, start = 0, end = 1;
    while (end < nums.length) {
        let tempMaxPos = 0;
        for (let i = start; i < end; ++i) {
            tempMaxPos = Math.max(i+nums[i], tempMaxPos);
        }
        start = end;
        end = tempMaxPos + 1;
        ++res;
    }
    return res;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)