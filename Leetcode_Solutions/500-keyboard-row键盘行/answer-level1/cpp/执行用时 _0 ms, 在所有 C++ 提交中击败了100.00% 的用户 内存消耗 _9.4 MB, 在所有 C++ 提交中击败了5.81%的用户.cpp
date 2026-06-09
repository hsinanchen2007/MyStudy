### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string hts[3] = {"qwertyuiopQWERTYUIOP", "ASDFGHJKLasdfghjkl", "zxcvbnmZXCVBNM"};
        int ht[128];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < hts[i].size(); j++){
                ht[hts[i][j]] = i;
            }
        }
        vector<string> res;
        for(int i = 0; i < words.size(); i++){
            bool flag = true;
            for(int j = 1; j < words[i].size(); j++){
                if(ht[words[i][j]] != ht[words[i][0]]){
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(words[i]);
        }
        return res;
    }
};
```