### 解题思路
将B直接复制到A中，再对其排序

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i = 0;i < n;++i)
        {
            //A.push_back(B[i]);
            A[m+i] = B[i]; 
        }
        int temp;
        for(int i = 0;i < m+n;++i)
        {
            for(int j = 0;j < m+n-i-1;++j)
            {
                if(A[j] > A[j+1])
                {
                    temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }
            }
        }
    }
};
```