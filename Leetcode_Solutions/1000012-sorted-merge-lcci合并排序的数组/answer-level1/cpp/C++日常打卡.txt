### 解题思路
插入并排序即可。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i = 0; i < n; ++i){
            A[m + i] = B[i];
        }
        sort(A.begin(),A.end());
    }
};
```