1. 遍历数组，先获得偶数，把奇数存储在临时数组中。
2. 偶数获得完毕后，再把奇数补在后边。

```c++ []
class Solution {
public:
    vector<int> sortArrayByParity(const vector<int>& A) {
        vector<int> ans;
        vector<int> odd;
        for (const auto& n : A)
            n & 0x1 ? odd.push_back(n) : ans.push_back(n);
        for (const auto& n : odd)
            ans.push_back(n);
        return ans;
    }
};
```
```python []
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        return sorted(A, key = lambda a : a%2)
```