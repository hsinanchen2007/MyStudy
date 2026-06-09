### 解题思路
主要是评论区大佬给的sort函数排序思路，谢谢！

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=0;
        int j=m;
        int len=m+n;
    for(j;j<len;j++){
            A[j]=B[i];
            i++;
        }
        std::sort(A.begin(),A.end());
    }
};
```