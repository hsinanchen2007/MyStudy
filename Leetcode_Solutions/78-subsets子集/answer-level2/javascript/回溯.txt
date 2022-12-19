### 解题思路
看到 「子集」、「组合」这样的词语，首先想到回溯算法。

全排列：N!

组合：N!

子集：2^N ，每个元素都可能存在或不存在。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const n = nums.length;
    const result = [];
    if (nums.length < 1) return [[]];
    const backTrace = (arr, currentIndex) => {
        result.push(arr);
        if (currentIndex >= n) return;
        for (let i = currentIndex; i < n; ++i) {
            arr.push(nums[i]);
            backTrace(arr.slice(), i+1);
            arr.pop();
        }
    }
    backTrace([], 0);
    return result;
};
```

### 复杂度
- 时间复杂度 O(N*2^N)
- 空间复杂度 O(2*N)