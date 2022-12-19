### 解题思路
内存消耗感觉可以再优化一下。比较菜鸡哈哈哈。
思路主要就是以第一个单词为基准，进行平行扫描，特别要注意单词长度的不同，如果检测到某一单词已经扫描完毕了，则直接返回当前结果。

### 代码
```cpp
//by thy
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string result;
        int word_num = strs.size();
        if(word_num <= 1)
        {
            result = word_num == 1 ? result + strs[0] : "";
            return result;
        }
        int fst_word_len = strs[0].length();
        for(int char_idx = 0; char_idx < fst_word_len; char_idx++)
        {
            char comp_char = strs[0][char_idx];
            for(int word = 1; word < word_num ; word++)
            {
                if(char_idx > strs[word].length() || comp_char != strs[word][char_idx])
                {
                    return result;
                }
            }
            result.push_back(comp_char);
        }
        return result;
    }
};
```