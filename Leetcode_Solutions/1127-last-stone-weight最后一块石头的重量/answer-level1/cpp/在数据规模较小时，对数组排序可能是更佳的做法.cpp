### 解题思路
不断将最大与第二大处理，直至剩下的石头数num<=1即可

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        int m1=0,m2=n-1,num=n;
        while(num>1){
        for(int i=0;i<n;i++)
        {
            if(stones[i]>stones[m1])
            {
               if(i==m2)
               {
                   m2=m1;
               }
                m1=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(stones[i]>=stones[m2]&&i!=m1)
            {
                m2=i;
            }
        }
        if(stones[m1]==stones[m2])
        {
            num-=2;
        }
        else
        {
            num--;
        }
        stones[m1]-=stones[m2];
        stones[m2]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(stones[i]>0)
            {
                return stones[i];
            }
        }
        return 0;
    }
};
```