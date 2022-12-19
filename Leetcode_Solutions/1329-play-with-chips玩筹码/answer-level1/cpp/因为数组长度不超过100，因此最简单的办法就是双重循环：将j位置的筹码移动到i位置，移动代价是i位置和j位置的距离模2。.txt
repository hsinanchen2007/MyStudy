```
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int res = 0;       
        for(int i=0;i<chips.size();i++)
        {
            int tmp = 0;
            for(int j=0;j<chips.size();j++)
            {
                tmp += abs(chips[j]-chips[i]) % 2;
            }
            if(res == 0 || tmp < res)
                res = tmp;
        }
        return res;
    }
};
```