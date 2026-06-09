### 解题思路
复制一个A，然后做合并排序

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> a(A);
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(a[i] < B[j]){
                A[i+j] = a[i];
                i++;
            }
            else{
                A[i+j] = B[j];
                j++;
            }
        }
        if(i == m){
            for(;j < n;j++) A[i+j] = B[j];
        }
        else for(;i < m;i++) A[i+j] = a[i];
    }
};
```