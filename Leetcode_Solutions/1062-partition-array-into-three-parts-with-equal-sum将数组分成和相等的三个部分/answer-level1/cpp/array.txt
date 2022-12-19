### 解题思路
array

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        for(int i=0;i<A.size();i++)
        {
            sum+=A[i];
        }
        if(sum%3!=0)
        {
            return false;
        }
        int k=0;
        int res=sum/3;
        int sum1=0;
        int sum2=0;
        for(;k<A.size()-2;k++)
        {
            sum1+=A[k];
            if(sum1==res) break;
        }
        k++;
        if(sum1!=res) return false;
        for(;k<A.size()-1;k++)
        {
            sum2+=A[k];
            if(sum2==res) break;
        }
        if(sum2!=res) return false;
        return true;
    }
};
```