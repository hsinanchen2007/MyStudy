#### 方法一：前缀和

我们用数组 `pre` 表示数组 `arr` 的「前缀异或和」，即

```
pre[0] = 0
pre[i] = arr[0] ^ arr[1] ^ ... ^ arr[i - 1]
```

其中 `^` 表示异或（`xor`）操作。这样以来，当我们要计算 `arr[Li]` 到 `arr[Ri]` 的异或值时，我们可以通过

```
pre[Li] ^ pre[Ri + 1] = (arr[0] ^ ... ^ arr[Li - 1]) ^ (arr[0] ^ ... ^ arr[Ri])
                      = (arr[0] ^ ... ^ arr[Li - 1]) ^ (arr[0] ^ ... ^ arr[Li - 1]) ^ (arr[Li] ^ ... ^ arr[Ri]) （异或运算的结合律）
                      = 0 ^ (arr[Li] ^ ... ^ arr[Ri]) （异或运算的逆运算，即 a ^ a = 0）
                      = arr[Li] ^ ... ^ arr[Ri]
```

在 $O(1)$ 的时间得到结果。

```C++ [sol1-C++]
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }
        vector<int> ans;
        for (const auto& query: queries) {
            ans.push_back(pre[query[0]] ^ pre[query[1] + 1]);
        }
        return ans;
    }
};
```

```Python [sol1-Python3]
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        pre = [0]
        for num in arr:
            pre.append(pre[-1] ^ num)
        ans = list()
        for x, y in queries:
            ans.append(pre[x] ^ pre[y + 1])
        return ans
```

**复杂度分析**

- 时间复杂度：$O(N + Q)$，其中 $N$ 是数组 `arr` 的长度，$Q$ 是数组 `queries` 的长度。我们需要 $O(N)$ 的时间计算前缀异或和数组，这样只需要 $O(1)$ 的时间，就能得到每一组查询的结果。因此总时间复杂度为 $O(N + Q)$。

- 空间复杂度：$O(N)$。