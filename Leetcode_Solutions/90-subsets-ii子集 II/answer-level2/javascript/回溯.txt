### 解题思路
同子集，使用回溯算法，不过每一次需要跳过重复的元素。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    const res = [], temp = [], n = nums.length;
    nums = nums.sort((a, b) => a - b);
    const backTrace = (arr, currentStart) => {
        res.push(arr);
        for (let i = currentStart; i < n; ++i) {
            if (i > currentStart && nums[i] === nums[i-1]) continue;
            arr.push(nums[i]);
            backTrace(arr.slice(), i + 1);
            arr.pop();
        }
    }
    backTrace(temp, 0);
    return res;
};
```

### 复杂度
- 时间复杂度 O(2^N)
- 空间复杂度 O(2^N)