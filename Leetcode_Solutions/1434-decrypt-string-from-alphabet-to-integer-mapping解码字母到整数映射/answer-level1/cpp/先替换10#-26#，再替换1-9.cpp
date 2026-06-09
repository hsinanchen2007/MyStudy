```
class Solution {
public:
    string freqAlphabets(string s) {
        // 替换'10#' - '26#'
        int idx = s.find('#');
        while(idx>=2)
        {
            string s1 = s.substr(0,idx-2);
            string s2 = s.substr(idx-2,2);
            string s3 = s.substr(idx+1);
            s = s1 + char('a'+stoi(s2)-1) + s3;
            idx = s.find('#');
        }
        // 替换'1' - '9'
        for(int i=0;i<s.length();i++)
        {
            if(s[i] >= '1' && s[i] <= '9')
            {
                stringstream stream;
                stream<<char('a' + s[i] - '1');
                s.replace(i, 1, stream.str());
            }
        }
        return s;
    }
};
```