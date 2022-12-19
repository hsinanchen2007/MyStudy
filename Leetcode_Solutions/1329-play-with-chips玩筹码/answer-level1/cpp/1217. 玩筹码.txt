就是看奇数和偶数哪个多……双百……
```
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int sum0=0,sum1=0;
        int n=chips.size();
        for(int i=0;i<n;++i)
        {
            if(chips[i]%2)
            {
                ++sum1;
            }
            else
            {
                ++sum0;
            }
        }
        return min(sum0,sum1);
    }
};
```
