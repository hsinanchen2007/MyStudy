### 解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
                int count[80000]={0};
                for(int i=0;i<A.size();i++)
                count[A[i]]++;    //a中的数出现过几次、
        int res=0;
        int num=0;
                for(int x=0;x<80000;x++)
                {
                    if(count[x]>=2)
                    {
                            res=res-x * (count[x]-1);   //数*数出现的次数
                            num=num+count[x]-1;   //重复次数
                    }
                    else if(num>0&&count[x]==0)
                   {
                       num--;  //如果还有重复并且遇到了没有见过的数就将重复数加到这个值
                        res+=x;
                   }
                }
                return res;
    }
};
```