#### 方法一：排序

我们计算出方阵中每一行的战斗力（即每一行的元素之和），再对它们进行排序即可。较优的排序方式有两种：

- 待排序的列表中的每个元素包括行号和该行的战斗力。在排序时，我们可以直接按照战斗力为第一关键字，行号为第二关键字进行排序，需要用到的数据都存储在列表内；

- 待排序的列表中的每个元素只包括行号。在排序时，我们需要自己定义比较函数，例如 `C++` 和 `Python` 中的 lambda 函数，将存储在外部的战斗力数据进行比较。

在排序完成后，我们返回结果的前 `k` 个元素。


```C++ [sol1-C++]
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> power;
        for (int i = 0; i < n; ++i) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            power.emplace_back(sum, i);
        }
        sort(power.begin(), power.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(power[i].second);
        }
        return ans;
    }
};
```

```C++ [sol1-C++17]
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> power;
        for_each(mat.begin(), mat.end(), [&](const vector<int>& line) {power.push_back(accumulate(line.begin(), line.end(), 0));});
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        sort(ans.begin(), ans.end(), [&](int i, int j) {return power[i] < power[j] || (power[i] == power[j] && i < j);});
        ans.resize(k);
        return ans;
    }
};
```

```Python [sol1-Python3]
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat)
        power = [sum(line) for line in mat]
        ans = list(range(n))
        ans.sort(key=lambda i: (power[i], i))
        return ans[:k]
```

**复杂度分析**

- 时间复杂度：$O(MN + M\log M)$。由于题目中保证了军人总是排在一行中的靠前位置，我们也可以通过二分查找的方法求出每一行中最右侧军人的位置，从而得到该行的战斗力，时间复杂度降低至 $O(M\log N + M\log M)$。

- 空间复杂度：$O(M)$。