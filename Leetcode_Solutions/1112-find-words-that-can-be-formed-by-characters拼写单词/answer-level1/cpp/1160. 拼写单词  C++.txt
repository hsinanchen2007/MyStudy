### 解题思路
统计单词各字母的数量 与字母表各字母的数量 比较大小
如果单词各字母数量都小于等于字母表对应字母的数量，则可以拼出
只要有一个字母不符合 则无法拼出

1 <= words[i].length, chars.length <= 100, 所有字符串中都仅包含小写英文字母
所以可以用vector<char> v(26) 做哈希统计

### 代码

```cpp
class Solution {
public:

    int countCharacters(vector<string>& words, string chars) {

        int total_size = 0;

        // vector<int> v_chars(26);
        vector<char> v_word(26);
        for(int i = 0; i < chars.size(); ++i)
        {
            ++v_chars.at(chars.at(i) - 'a');
        }

        for(int i = 0; i < words.size(); ++i)
        {
            // vector<int> v_chars(26);
            vector<char> v_word(26);
            for(int j = 0; j < words.at(i).size(); ++j)
            {
                ++v_word.at(words.at(i).at(j) - 'a');
            }

            int j = 0;
            for(; j < v_word.size(); ++j)
            {
                if(v_word.at(j) > v_chars.at(j)) //拼不出
                {
                    break;
                }
            }
            if(j == v_word.size()) //拼出了
            {
                total_size += words.at(i).size();
            }
        }

        return total_size;
    }
};
```