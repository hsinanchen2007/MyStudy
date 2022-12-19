### 解题思路

字符串操作，边界情况很多。

### 代码

```cpp
class Solution {
public:
    string validIPAddress(string IP) {
        bool v4 = IP.find('.') != string::npos;
        bool v6 = IP.find(':') != string::npos;
        if(v4 && v6)
            return "Neither";
        if(!v4 && !v6)
            return "Neither";
        
        if(v4 && validIPv4(IP))
            return "IPv4";
        else if(v6 && validIPv6(IP))
            return "IPv6";
        
        return "Neither";
        
    }
    
    bool validIPv4(string IP) {
        vector<string> tokens;
        tokenize(IP, ".", tokens);
        if(tokens.size() != 4)
            return false;
        for(int i=0; i<4; i++) {
            for(char c: tokens[i]) {
                if(c < '0' || c > '9')
                    return false;
            }
            if(tokens[i].size() == 0 || tokens[i].size() > 3)
                return false;
            if(tokens[i][0] == '0') {
                if(i == 0)
                    return false;
                if(tokens[i].size() > 1)
                    return false;
            }
            int val = stoi(tokens[i]);
            if(val < 0 || val > 255)
                return false;
            if(i == 0 && val == 0)
                return false;
        }
        return true;
    }
    
    bool validIPv6(string IP) {
        vector<string> tokens;
        tokenize(IP, ":", tokens);
        if(tokens.size() != 8)
            return false;
        for(int i=0; i<8; i++) {
            int count = 0;
            for(char c: tokens[i]) {
                bool valid = (c >= '0' && c <= '9') 
                    || (c >= 'a' && c <= 'f')
                    || (c >= 'A' && c <= 'F');
                if(!valid)
                    return false;
                count++;
            }
            if(count == 0 || count > 4)
                return false;
        }
        return true;
    }
    
    void tokenize(string s, const char *d, vector<string> &res) {
        int start = 0;
        int end = s.find(d);
        while(end != string::npos) {
            res.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(d, start);
        }
        res.push_back(s.substr(start, s.size() - start));
    }
};
```