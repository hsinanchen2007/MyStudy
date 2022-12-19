```
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> strs(numRows);
        string res = "";
        bool upDown = false;  // false 表示向下走，true表示向上走
        int row = 0;
        for(int i=0; i<s.size(); i++) {
            strs[row] += s[i];
            if(row == 0)
                upDown = false;
            else if(row == numRows-1)
                upDown = true;
            if(!upDown) // 表示向下走
                row++;
            else // 表示向上走
                row--;
        }
        for(string str : strs)
            res += str;
        return res;
    }
};
```
