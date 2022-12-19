### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int MaxSize=m+n;
        while(MaxSize--&&m>0&&n>0){
            if(A[m-1]>B[n-1]){
                A[MaxSize]=A[m-1];
                m--;
            }
            else{
                A[MaxSize]=B[n-1];
                n--;
            }
        }
        if(n>0){
            while(n--){
                A[n]=B[n];
            }
        }
    }
};
```