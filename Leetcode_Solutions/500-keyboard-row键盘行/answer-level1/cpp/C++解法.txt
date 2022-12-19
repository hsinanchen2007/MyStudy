### 解题思路
先判断是哪一行，再遍历每个word检查是否都在该行

### 代码

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> WORDS = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> res;
        string tmp = "";
        for(auto word: words){
            for(auto WORD : WORDS){ //先查找是哪一行 
                char ch = word[0];
                if(ch >= 'A' && ch <= 'Z')
                    ch = 'a'+ch - 'A';
                if(WORD.find(ch)!=WORD.npos)
                    tmp = WORD;
            }
            // 逐一判断words中字母是否在该行中
            int i = 0;
            for(;i<word.size();i++){
                char ch = word[i];
                if(ch >= 'A' && ch <= 'Z')
                    ch = 'a'+ch - 'A';
                if(tmp.find(ch) == tmp.npos)
                    break;
            }
            if(i == word.size())
                res.push_back(word);
        }
        return res;
    }
};
```