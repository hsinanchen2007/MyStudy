```
class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0, cnt = 0;
        char t = 34;
        chars.push_back(char(127)); // 末尾补上一个边界字符，方便操作
        for(auto c : chars)
        {
            if(t == c) 
            {
                cnt++;
            }
            else
            {
                if(35 <= t && t <= 126) chars[res++] = t;
                if(cnt > 1)
                {
                    string tmp = to_string(cnt);
                    for(auto ch : tmp) chars[res++] = ch;
                }
                t = c;
                cnt = 1;
            }
        }
        return res;
    }
};
```