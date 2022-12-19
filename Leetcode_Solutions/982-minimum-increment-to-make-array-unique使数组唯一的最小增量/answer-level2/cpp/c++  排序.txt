### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int n = A.size(),res = 0,tacken=0;
        for(int i = 1; i < n; i++)
        {
            if(A[i] == A[i-1])
            {
                tacken++;  //重复次数++
                res-=A[i-1];//结果减去A[i-1]
            }
            else
            {
                int given = min(tacken,A[i] - A[i-1]-1);//取[A[i-1]，A[i]]区间和重复次数的最小值，
                res += A[i-1]*given + (given+1)*given/2;
                tacken -= given;
            }
        }
        if(tacken > 0)      //判断最后是否还有还有没有重复的
        {
            res += tacken*A.back() + (tacken+1)*tacken/2;
        }
        return res;
    }
};
```