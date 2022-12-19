### 解题思路
题目中涉及到“最大”、“最小”，不妨先排个序看看。

排完序之后，我们可以观察到：一个元素是最大元素：当且仅当它是被选取元素中最右边的一个；一个元素是最小元素，当且仅当它是被选取元素中最左边的一个。

所以说，假设排序后一个元素左边有$left$个元素，右边有$right$个元素，那么这个元素作为最小值出现的子序列一共有$2^{right}$个（右边的每个元素可以选取或不选取）；而作为最大值出现的子序列一共有$2^{left}$个。因此，元素A[i]对最后的总和的贡献就等于：

$$(2^{right}-2^{left})\cdot A[i]=(2^{n - i - 1} - 2^i)\cdot A[i]$$

那么，我们只要预先计算好2的各个幂次的值，就能很轻松地求出最后的结果了。

### 代码

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        vector<ll> two(n + 1);
        two[0] = 1;
        for (int i = 1; i <= n; ++i)
            two[i] = (two[i - 1] << 1) % MOD;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int left = i;
            int right = n - i - 1;
            ans = (ans + (two[left] - two[right]) * A[i]) % MOD;
        }
        return (ans + MOD) % MOD;
    }
};
```