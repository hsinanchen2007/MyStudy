### 解题思路

将sort函数的的compare重写，直接用sort函数实现按照costs[1]-costs[0]升序排序，前N个取第一位，后N个取第二位；
### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        return (a[1]-a[0])>(b[1]-b[0]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int ans=0;
        int N=costs.size()/2;
        sort(costs.begin(),costs.end(),cmp);
        int i=0;
        while(i<costs.size())
        {
            if(i<N)
            {
                ans+=costs[i][0];
            }
            else 
                ans+=costs[i][1];
            i++;
        }
        return ans;
    }
    
};
```