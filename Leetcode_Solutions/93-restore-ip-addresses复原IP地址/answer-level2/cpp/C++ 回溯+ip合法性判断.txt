```
class Solution {
public:
    vector<string> ret;
    int string2Int(string s, int index) {
        return (s[index] - '0') * 100 + (s[index + 1] - '0') * 10 + s[index + 2] - '0';
    }
    vector<string> restoreIpAddresses(string s) {
        string ip;
        dfs(s, ip, 0, 0);
        return ret;
    }
    void dfs(string s, string ip, int index, int layer) {
        string tmp;
        for (int i = 0; i < 3; ++i) {
            //第一个分支保证剩余的数字能构成合理的ip码
            if ((s.size() - (index + i + 1) >= (3 - layer)) && (s.size() - (index + i + 1) <= 3 * (3 - layer))) {
                //第二个分支保证取的ip每部分是合理的，i = 0一定合理，i > 0,那么要求首位不为0，并且值小于256
                if (i == 0 || (s[index] != '0' && (i < 2 || (i == 2 && string2Int(s, index) <= 255)))) {
                    if (layer == 3) {                             //到了最后一层，则保存对应ip地址
                        tmp = ip + s.substr(index, i + 1);
                        ret.push_back(tmp);
                    } else {
                        tmp = ip + s.substr(index, i + 1) + ".";   //记录ip地址中间值，并dfs
                        dfs(s, tmp, index + i + 1, layer + 1);
                    }
                }
            }
        }
    }
};
```
