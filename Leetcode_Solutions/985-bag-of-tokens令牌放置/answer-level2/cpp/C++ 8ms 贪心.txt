```
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int len=tokens.size();
        sort(tokens.begin(), tokens.end());
        int res=0;
        int buy_index=0;
        int sell_index=len-1;
        int cur_power=P, cur_score=0;
        while(buy_index<=sell_index) {
            while(buy_index<=sell_index&&cur_power>=tokens[buy_index]) {  // 下标
                cur_power-=tokens[buy_index];
                buy_index++;
                cur_score++;
            }
            if(cur_score>res) {
                res=cur_score;
            }
            while(buy_index<=sell_index&&cur_power<tokens[buy_index]&&cur_score) {
                cur_power+=tokens[sell_index];
                cur_score--;
                sell_index--;
            }
            if(buy_index<=sell_index&&cur_power<tokens[buy_index]) {  //边界条件，买不了，就跳出循环。
                break;
            }
        }
        return res;
    }
};
```
