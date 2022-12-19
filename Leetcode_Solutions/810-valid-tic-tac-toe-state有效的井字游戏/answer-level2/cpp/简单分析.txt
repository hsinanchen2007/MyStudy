```
class Solution {
public:
    int left,right;
    bool judge1,judge2;
    bool validTicTacToe(vector<string>& board) {
        for(auto&it:board) {
            for(auto&site:it) {
                if(site=='X') left++;
                else if(site=='O') right++;
            }
        }
        if(left<right||left>right+1) return false;//先手数量要么等于后手数量,要么比后手数量多一
        judge1 = find(board,'X');//判断先手是否赢得胜利
        judge2 = find(board,'O');//判断后手是否赢得胜利
        if(judge1&&judge2) return false;//同时胜利不存在
        if(judge1&&!judge2) {
            if(left==right+1) return true;//如果先手赢那么先手数量一定比后手多一
            else return false;//反证法如果它们数量相等先手赢的话，后手是不可能下最后一步的
        }else if(judge2&&!judge1) {
            if(left==right) return true;//如果后手赢那么后手数量一定和先手相等
            else return false;//因为它们是轮流下，所以后手每一步下完后的数量都和先手相等，包括胜利，而胜利后先手是不能再走了的
        }else
            return true;//其它情况都可存在
    }
    bool find(vector<string>& s,char ch) {
        if(s[0][0]==ch&&s[0][0]==s[0][1]&&s[0][1]==s[0][2]) return true;
        if(s[1][0]==ch&&s[1][0]==s[1][1]&&s[1][1]==s[1][2]) return true;
        if(s[2][0]==ch&&s[2][0]==s[2][1]&&s[2][1]==s[2][2]) return true;
        if(s[0][0]==ch&&s[0][0]==s[1][0]&&s[1][0]==s[2][0]) return true;
        if(s[0][1]==ch&&s[0][1]==s[1][1]&&s[1][1]==s[2][1]) return true;
        if(s[0][2]==ch&&s[0][2]==s[1][2]&&s[1][2]==s[2][2]) return true;
        if(s[0][0]==ch&&s[0][0]==s[1][1]&&s[1][1]==s[2][2]) return true;
        if(s[2][0]==ch&&s[2][0]==s[1][1]&&s[1][1]==s[0][2]) return true;
        return false;
    }
};
```
