***Talk is cheap. Show me the code.***

**回溯、剪枝**

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        loc.resize(5);      //存储 pos 位置，收尾是确定的，1、2、3 需要计算
        loc[0] = 0;         
        loc[4] = s.size();
        backtrack(s, 1);
        return result;
    }
    
    void backtrack(const string &s, int round) {
        if (round == 4) {
            if (loc[4] - loc[3] > 3) return;                         //剪枝
            if (loc[4]-loc[3]>1 && s[loc[3]]=='0') return;           //剪枝
            if (stoi(s.substr(loc[3], loc[4]-loc[3])) < 256) {       //剪枝
                string ip = s.substr(loc[0], loc[1]-loc[0]);
                for (int i = 1; i <= 3; i++) {
                    ip.push_back('.');
                    ip += s.substr(loc[i], loc[i+1]-loc[i]);
                }
                result.push_back(ip);
            }
            return;
        }
        
        if (loc[round-1] + 1 >= loc[4]) return;              //剪枝
        loc[round] = loc[round-1] + 1;
        backtrack(s, round+1);
        
        if (s[loc[round-1]] == '0') return;                  //剪枝

        if (loc[round-1] + 2 >= loc[4]) return;              //剪枝
        loc[round] = loc[round-1] + 2;
        backtrack(s, round+1);
        
        if (loc[round-1] + 3 >= loc[4]) return;              //剪枝
        if (stoi(s.substr(loc[round-1], 3)) < 256) {         //剪枝
            loc[round] = loc[round-1] + 3;
            backtrack(s, round+1);
        }
    }
    
private:
    vector<int> loc;
    vector<string> result;
};

```

`string substr (size_t pos = 0, size_t len = npos) const;`    //注意这个函数的参数