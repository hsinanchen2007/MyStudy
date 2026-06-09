### 解题思路
思路：从队尾开始选择最大的元素插入

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        while(m>0&&n>0)
        {
            if(A[m-1]>=B[n-1])
            {
                A[m+n-1]=A[m-1];
                m--;
            }
            else
            {
                A[m+n-1]=B[n-1];
                n--;
            }
        }
        if(m==0&&n!=0)
        {
            for(int i=0;i<n;i++)
            {
                A[i]=B[i];
            }
        }
    }
};
```