```
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(101);
        //起点相同的片段将终点更新为最大的那一个
        for (auto & clip : clips) {
            dp[clip[0]] = dp[clip[0]] > clip[1] ? dp[clip[0]] : clip[1];
        }
        int next_max = dp[0], cur_max = 0, count = 0;
        while (next_max != cur_max){
            count++;
            cur_max = next_max;
            if(cur_max >= T){
                return count;
            }
            //在本片段内任何一个时间点切一刀，再从这一点走一次所能达到的最大终点
            for (int i = 0; i <= cur_max; ++i) {
                next_max = next_max > dp[i] ? next_max : dp[i];
            }
        }
        return -1;
    }
};
```
