### 解题思路
先把两个容器合并，然后用sort函数进行排序，简单高效。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int total = m +n;
        int j=0;
        for(int i=m;i<total;i++){
            A[i] = B[j];
            j++;
        }
        sort(A.begin(),A.end());
    }
};
```