### 解题思路
此处直接用库函数搞了。当然你也可以用双指针慢慢遍历改。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> t = vector(A.begin(), A.begin()+m);
        t.insert(t.end(), B.begin(), B.end());
        sort(t.begin(), t.end());
        A = t;
    }
};
```