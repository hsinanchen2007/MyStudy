### 解题思路
此处撰写解题思路
记录以Ai结尾的等差数列数，状态转移方程为
if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                b[i]=b[i-1]+1;
            }
### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<=2) return 0;
        int b[A.size()]={0},num=0;
        for(int i=2;i<A.size();i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                b[i]=b[i-1]+1;
                if(b[i]>0)
                {
                    num+=b[i];
                }
            }
        }
        return num;
    }
};
```