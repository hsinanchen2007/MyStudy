/*
dp[i][j].fir 表示，对于 piles[i...j] 这部分石头堆，先手能获得的最高分数。
dp[i][j].sec 表示，对于 piles[i...j] 这部分石头堆，后手能获得的最高分数。

举例理解一下，假设 piles = [3, 9, 1, 2]，索引从 0 开始
dp[0][1].fir = 9 意味着：面对石头堆 [3, 9]，先手最终能够获得 9 分。
dp[1][3].sec = 2 意味着：面对石头堆 [9, 1, 2]，后手最终能够获得 2 分。
*/



```
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int _Len = piles.size();
//        VecVec dp(_Len, VecPair(_Len));
        vector<vector<pair<int,int>>> dp(_Len, vector<pair<int, int>>(_Len));
        for(int i = 0; i < _Len; i ++){
            for(int j = 0; j < _Len; j ++){
                if(i == j){
                    dp[i][j].first = piles[i];
                    dp[i][j].second = 0;
                }
                else {
                    dp[i][j].first = 0;
                    dp[i][j].second = 0;
                }
            }
        }

                //斜着遍历
        for(int l = 2; l <= _Len; l++){
            for(int i = 0; i <= _Len-l; i++){
                int j = i + l - 1;
                int left = piles[i] + dp[i+1][j].second;//这一轮我们先手，下一轮是后手,所以只能选择second
                int right = piles[j] + dp[i][j-1].second;

                if(left > right){
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i+1][j].first;//后手面对石头堆（i+1,j）,只能选择其中的最优解
                }
                else{
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
        pair<int,int> res = dp[0][_Len-1];
        return res.first - res.second;
    }
};
```

