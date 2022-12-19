```
class Solution {
public:
    string convert(string s, int numRows) {
        string ss = "";
        if(s=="") return string("");
        int cnt = 0;
        int len = s.length();
        int once = 2*numRows-2==0 ? 1 : 2*numRows-2;
        int fullRound = len/once;
        int remainCol = numRows==1 ? 0 : (len%once>numRows ? 1+len%once-numRows : 1);
        int totalCols = numRows==1? len : (numRows-1)*fullRound+remainCol;
        vector<vector<char>> res( numRows, vector<char>(totalCols,' ') );
        // cout << once << ", " << fullRound << ", " << remainCol << ", " << totalCols << endl;
        for(int i=0; i<totalCols, cnt<s.length();)
        {
            if(cnt >= numRows)
            {
                res[2*numRows-cnt-2][i] = s[cnt];
                cnt++;
            }
            else{
                res[cnt][i] = s[cnt];
                cnt++;
            }
            if(cnt >= numRows) i++;
            if(cnt == once)
            {
                cnt = 0;
                s.erase(0,once);
            }
        }
        for(int i=0; i<numRows; i++)
        {
            for(int j=0; j<totalCols; j++)
            {
                if(res[i][j]!=' ') ss.push_back(res[i][j]);
            }
        }
        return ss;
    }
};
```
