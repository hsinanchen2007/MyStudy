### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip("");
        GetIPs(s, 0, 0, res, ip);
        return res;    
    }

    void GetIPs(string s, int index, int count, vector<string>& res, string ip) {
        //cout<<index<<" "<<count<<endl;
        if (index == s.size()) {
            if (count == 4) {
                ip.pop_back();
                res.push_back(ip);
                return;
            } else {
                return;
            }
        }
        if(count == 4) {
            return;
        }
        for(int i = 1; i < 4; ++i) {
            if (index+i > s.size()) {
                break;
            }
            string tmp = s.substr(index, i);
            int val = stoi(tmp);
            if (val > 255) {
                break;
            } else if (i > 1 && s[index] == '0') {
                break;
            }
            GetIPs(s, index+i, count+1, res, ip+tmp+".");
        } 
    }
};
```