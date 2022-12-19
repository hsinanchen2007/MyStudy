### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char,int> map;
        int bulls = 0,cows = 0,i;
        string res = "";

        for(i = 0;i < s.size();i++)
            map[s[i]]++;
        
        for(i = 0;i < g.size();i++){
            if(g[i] == s[i]) {
                bulls++;
                map[g[i]]--;
            }
        }
        for(i = 0;i < g.size();i++){
            if(g[i] != s[i] && map[g[i]] != 0){
                map[g[i]]--;
                cows++;
            }
        }

        res = to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};

```