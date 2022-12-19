### 方法一
先排序，然后逐步比较，注意去重的判断条件

### 代码

```javascript
var findPairs = function(nums, k) {
    nums.sort((a, b) => a - b);
    let n = nums.length, count = 0;

    for (let i = 0; i < n - 1; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (let j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            if (nums[j] - nums[i] > k) break;

            if (nums[j] - nums[i] == k) {
                count++;
            }
        }
    }
    return count;
};
```
### 方法二
两数之和的变形，对于任何一个`n`，寻找`n - k`和`n + k`，我们只需要记录diff对中左值(最小)即可

### 代码
```javascript
var findPairs = function(nums, k) {
    if (k < 0) return 0;
    let visit = new Set(), map = new Set();

    for (let n of nums) {
        if (visit.has(n - k)) {
            map.add(n - k);
        }
        if (visit.has(n + k)) {
            map.add(n);
        }
        visit.add(n);
    }
    return map.size;
}
```

