```
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int pre = 0;
        int pos = s.find(" ", pre);
        while(pos!=string::npos){
            for(int i = pos-1;i>=pre;i--){
                res += s[i];
            }
            res += " ";
            pre = pos+1;
            pos = s.find(" ", pre);
        }
        for(int i = s.length()-1;i>=pre;i--){
            res += s[i];
        }
        return res;
    }
};
```