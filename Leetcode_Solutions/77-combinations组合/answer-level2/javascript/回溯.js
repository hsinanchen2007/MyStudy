### 解题思路
典型的回溯。

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    const resArr = [];
    if (k > n) return resArr;
    const backTrace = (arr, m) => {
        if (m >= k) {
            resArr.push(arr);
            return;
        }
        for (let i = m + 1; i <= n; ++i) {
            if (!arr.length || i > arr[arr.length-1]) {
                arr.push(i);
                backTrace(arr.slice(), m + 1);
                arr.pop();
            }
        }
    }
    backTrace([], 0);
    return resArr;
};
```

### 复杂度
- 时间复杂度 O(k*Cnk) Cnk = N!/((N-k)!k!)
- 空间复杂度 O(Cnk)