```
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> ans(min(numRows,int(s.size())));
        int curRow = 0;
        bool isGoingDown = false;
        for(char c:s){
            ans[curRow] += c;
            if(curRow==0 || curRow==numRows-1) isGoingDown=!isGoingDown;
            curRow += isGoingDown?1:-1;
        }
        string ret;
        for(string s1:ans) ret+=s1;
        return ret;
    }
};
```
