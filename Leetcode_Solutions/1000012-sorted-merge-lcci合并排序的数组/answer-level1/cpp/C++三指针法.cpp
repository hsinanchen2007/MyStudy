从后往前遍历，三个下标
- idx指向合并后数组的当前值
- a_idx指向A数组的当前值
- b_idx指向A数组的当前值

只要b_idx>=0，就进行循环
- 如果a_idx不为零，就比较A[a_idx]和B[b_idx]的值，把较大的放在A[idx]处，并减小相应的下标值
- 如果a_idx为0，那么只需将B[b_idx]放到A[idx]处，并减小相应的下标

```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        if(m == 0 && n == 0)
            return;

        int a_idx = -1;
        int b_idx = -1;
        
        if(m > 0)
            a_idx = m-1;
        if(n > 0)
            b_idx = n-1;
        
        int idx = m+n-1;

        while(b_idx >= 0)
        {
            if(a_idx >= 0)
            {
                if(A[a_idx] > B[b_idx])
                {
                    A[idx] = A[a_idx];
                    --a_idx;
                }
                else
                {
                    A[idx] = B[b_idx];
                    --b_idx;
                }
                
            }
            else
            {
                A[idx] = B[b_idx];
                --b_idx;
            }
            --idx;
        }

    }
};
```
