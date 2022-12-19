### 解题思路
首先检查数组总和是否可以被3整除，不是则返回flase
接着计算均值，并检查数组中是否存在3个以上均值，存在则返回true

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int sum=0,_sum=0;
        int flag=0,i=0;

        for(i=0;i<A.size();i++)
        {
            sum+=A[i];        
        }
        if (sum%3!= 0) return false;
        sum/=3;

        for(i=0; i<A.size(); i++)
        {
            _sum+=A[i];
            if(_sum==sum)
            {
                _sum=0;
                flag++;
            }
        }

        if(flag>=3) return true;
        else return false;
    }
};


```