### 解题思路
可以暴力搜索O(N^3)
可以O(N^2)

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        return numTeamsMid(rating);
        // return numTeamsViolence(rating);// 暴力
    }
    int numTeamsViolence(vector<int>& rating){
        int res = 0;
        for(int i=0; i<rating.size(); ++i){
            for(int j=i+1; j<rating.size(); ++j){
                for(int k= j+1; k<rating.size(); ++k){
                    if(rating[j] < rating[i] && rating[k] < rating[j]) ++res;
                    if(rating[j] < rating[k] && rating[i] < rating[j]) ++res;
                }
            }
        }
        return res;
    } // 暴力O(N^3)
    // 寻找最中间点0
    int numTeamsMid(vector<int>& rating){
        int res = 0;
        for(int i=1; i<rating.size(); ++i){
            int left_low = 0;
            int right_high = 0;
            int left_high = 0;
            int right_low = 0;
            for(int j=0; j<i; ++j){
                if(rating[j] < rating[i]) ++left_low;
                if(rating[j] > rating[i]) ++left_high;
            }
            for(int j=i+1; j<rating.size(); ++j){
                if(rating[j] > rating[i]) ++right_high;
                if(rating[j] < rating[i]) ++right_low;
            }
            res += left_low * right_high;
            res += left_high * right_low;
        }// 左边的小于右边的
        return res;
    }
};
```