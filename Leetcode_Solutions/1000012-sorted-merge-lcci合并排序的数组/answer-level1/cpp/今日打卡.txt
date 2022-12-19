### 解题思路
此处撰写解题思路
写了好久没写出来，最后发现官方题解这么简单
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i=0;i!=n;++i){
        A[m+i]=B[i];
    }
    sort(A.begin(),A.end());
    }
};
```