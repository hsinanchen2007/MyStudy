代码如下
说明：本题和719、378为一类题目，建议这三道题都做一做！

```Java
public int findKthNumber(int m, int n, int k) {
    int lo = 1, hi = m * n + 1;
    int mid, count;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        count = 0;
        for (int i = 1; i <= m; i++) {
            count += (mid/i > n ? n : mid/i);
        }
        if (count >= k) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！
