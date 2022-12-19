### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int k = m + n - 1;
        int a = m - 1;
        int b = n - 1;
        while(a>=0 && b>=0){
            if(A[a] > B[b]){
                A[k] = A[a];
                a--;
                k--;
            }else{
                A[k] = B[b];
                b--;
                k--;
            }
        }
        while(a >= 0){
            A[k] = A[a];
            a--;
            k--;
        }
        while(b >= 0){
            A[k] = B[b];
            b--;
            k--;
        }
        for(int i = 0; i < m + n; i++){
            printf("%d",A[i]);
        }
    }
};
```