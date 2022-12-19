### 解题思路
用A中元素构建一个新数组，然后用类似归并排序中的归并方法构建原数组A

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> C(A.begin(), A.begin() + m);
        int i = 0, j = 0;
        while(i < m && j < n){
            while(i != m && C[i] <= B[j]){
                A[i + j] = C[i];
                i++;
            }
            while(i != m && j != n && C[i] > B[j]){
                A[i + j] = B[j];
                j++;
            }
        }
        if(i == m) while(j < n){
            A[i + j] = B[j];
            j++;
        }
        if(j == n) while(i < m){
            A[i + j] = C[i];
            i++;
        }
    }
};
```