### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        reverse(A.begin(),A.end());
        for(int i=0;i<B.size();i++)
        {
            A[i] = B[i];
        }
        sort(A.begin(),A.end());
    }
};
```