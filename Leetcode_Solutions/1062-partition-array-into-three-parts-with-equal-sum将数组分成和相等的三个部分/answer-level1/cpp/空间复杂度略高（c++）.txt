### 解题思路
我认为的坑：
两个分隔点不能重合，不能在最后。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int sum{};
        for(int i=0;i<A.size();++i)
        {
            sum+=A[i];
        }
        if(sum%3)
        {
            return false;
        }
        int tem{};
        bool flag=false;
        int ii{};
        for(int i=0;i<A.size();++i)
        {
            tem+=A[i];
            if(flag==true)
            {}
            else
            {
                if(tem==sum/3)
                {
                    flag=true;
                    ii=i;
                }
            }
            if(i!=ii&&tem==sum/3*2&&flag==true&&i!=A.size()-1)
            {
                return true;
            }
                
        }
        return false;
    }
};
```