### 解题思路
遍历word的每个单词，然后查temp_chars,如果word的单词里没有chas包含的字母，就直接跳出查下一个单词。如果在chars里查出了相应的单词，则删除单词所对应的字母

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        string temp_chars = chars;
        vector<string>:: iterator i = words.begin();
        for(i; i != words.end(); ++i){
            for(char c : *i){
                if(temp_chars.find(c) == temp_chars.npos){
                    *i = "~"+*i;
                    break;
                }
                else temp_chars.erase(temp_chars.find(c), 1);
            }
            temp_chars = chars;
        }
        for(string j : words){
            if(j[0] == '~') continue;
            res += j.size();
        };
        return res;
    }
};
```