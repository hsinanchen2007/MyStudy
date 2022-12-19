### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int p=A.size()-1;
        int i=m-1;
        int j=n-1;
        while(p>=0){
            if(i>=0&&j>=0){
                if(A[i]>=B[j]){
                    A[p]=A[i];
                    i--;
                }
                else{
                    A[p]=B[j];
                    j--;
                }
            }
            else if(i>=0){
                A[p]=A[i];
                i--;
            }
            else{
                A[p]=B[j];
                j--;
            }
            p--;
        }
    }
};
```