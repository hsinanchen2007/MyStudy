1. 该题目比较简单，直接看代码。
2. 如果有n个等价的骨牌，则等价的骨牌对的数目为n*(n-1)/2;
```
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int sum[11][11];
        int res = 0;
        
        memset(sum,0,sizeof(sum));
        for(auto d : dominoes){
            sum[d[0]][d[1]]++;
        }
        
        for(int i = 0;i <=10; ++i){
            for(int j = 0;j < i; ++j){
                int n = sum[i][j] + sum[j][i];
                res += n*(n-1)/2;
            }
        }
        for(int i = 0;i <= 10; ++i){
            res += sum[i][i]*(sum[i][i]-1)/2;
        }
        return res;
    }
};
```