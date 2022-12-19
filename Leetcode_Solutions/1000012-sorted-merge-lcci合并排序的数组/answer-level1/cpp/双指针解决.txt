### 解题思路
执行用时 :12 ms, 在所有 C++ 提交中击败了28.76%的用户
内存消耗 :11.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A,int m,vector<int>& B,int n) 
    {
        int s = A.size() - 1;
        int p = m - 1;
        int q = n - 1;

        while((p >= 0) && (q >= 0))
        {
            if(A[p] > B[q])
            {
                A[s--] = A[p--];
            }
            else
            {
                A[s--] = B[q--];
            }
        }

        while(p >= 0)
        {
            A[s--] = A[p--];
        }

        while(q >= 0)
        {
            A[s--] = B[q--];
        }
    }
};
```