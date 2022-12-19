### 解题思路

把矩阵状态转化成二进制数，把每个点对应的需要反转的点转成二进制数，然后二进制异或宽搜就行了。

另外发现python3的线上测试已经更新到3.8了，集合的遍历序不是哈希序而变成添加序了，海象语句也能用了。

### 代码

```python []
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m, n, b = len(mat), len(mat[0]), int(''.join(map(str, itertools.chain(*mat))), 2)
        s, v, d, ans = {b}, {b}, set(), 0
        for t in range(m * n):
            k = 1 << t
            if t // n > 0:
                k += 1 << (t - n)
            if t // n < m - 1:
                k += 1 << (t + n)
            if t % n > 0:
                k += 1 << t - 1
            if t % n < n - 1:
                k += 1 << t + 1
            d.add(k)
        while s:
            t = set()
            for i in s:
                if not i:
                    return ans
                for j in d:
                    k = i ^ j
                    if k not in v:
                        t.add(k)
                        v.add(k)
            s = t
            ans += 1
        return -1


```
![image.png](https://pic.leetcode-cn.com/8f7c5a5b5b23475197fe5f379eb76603c490919873a3813c1827158c5b1af4dd-image.png)
