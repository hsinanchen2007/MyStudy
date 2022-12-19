### 解题思路
从后向前将较大的数写入数组A中
A[k--]等价于A[k] k--

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j >= 0){
            if(A[i] < B[j])
                A[k--] = B[j--];
            else
                A[k--] = A[i--];
        }
        // if(j >= 0)
        //     for(int ii = 0;ii <= j;ii++)
        //         A[ii] = B[ii];
        //用以下代码效率更高
        while(j>=0) A[k--] = B[j--];
    }
};
```