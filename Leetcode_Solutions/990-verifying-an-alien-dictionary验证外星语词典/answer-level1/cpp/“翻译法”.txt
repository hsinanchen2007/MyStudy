执行用时 :8 ms, 在所有 C++ 提交中击败了84.96%的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了89.36%的用户

对不起，我看不懂外星文，但我可以把它“翻译”成正常顺序的英文。

```
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        

        
        string last_words_translate = "";//记录上一个单词的“翻译”
        
        for(int i=0; i<words.size(); i++){//嵌套循环遍历单词表
            
            string next_words_translate = "";//记录现在这个单词的“翻译”
            
            for(int j=0; j<words[i].size(); j++){
                
                auto pos = order.find(words[i][j]);//找出现在指向的字母在order表中的相对位置
                
                next_words_translate += char(pos + 'a');//将每个单词中的每个字母按order表中的相对顺序"翻译"成正常顺序的字母
            }

            if(next_words_translate < last_words_translate)
                return false;
            
            last_words_translate = next_words_translate;
        }
        
        
        return true;
    }
};
```
