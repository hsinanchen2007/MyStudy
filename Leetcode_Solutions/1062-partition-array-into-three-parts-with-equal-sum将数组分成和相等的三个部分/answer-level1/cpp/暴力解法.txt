### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int num=0,average=0,count=0,i=0,j=0;
        for(int i=0;i<A.size();i++)num+=A[i];
        if((average=num/3)!=num/double(3))return false;
        count=average;
        for(;i<A.size();i++)
        {
            count-=A[i];
            if(count==0)
            {
                j=i+1;break;
            }
        }
        for(;j<A.size();j++)
        {
            average-=A[j];
            if(average==0&&j<A.size()-1)return true;
        }
        return false;
    }
};
```