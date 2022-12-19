```
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // step 1: 调整次序
        for(int i=0;i<dominoes.size();i++)
        {
            if(dominoes[i][0] > dominoes[i][1])
            {
                int tmp = dominoes[i][0];
                dominoes[i][0] = dominoes[i][1];
                dominoes[i][1] = tmp;
            }
        }

        // step 2: 统计次数
        map<vector<int>,int> count;
        for(auto d : dominoes)
        {
            count[d] += 1;
        }

        // step 3: 计算等价数量（全排列=n*(n-1)/2）
        int res = 0;
        for(auto d : count)
        {
            int n = count[d.first];
            res += (n*(n-1)/2);
        }

        return res;
    }
};
```