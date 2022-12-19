### 解题思路
这里的思路比较简单，主要是开辟26大小的vector<int> , 每个位置对应一个字母（这个需要注意），然后在每个元素中记录每个字母出现的次数

遍历每个单词， 遇到一个字符，则将对应字母的个数 -1， 这样就会判断是否满足。

注意读懂题意： 对每个单词遍历时，字母表是完整的

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> char_number(26, 0);
        for (auto tmp : chars) {
            ++char_number[tmp-'a'];
        }

        int length = 0;
        for (auto word : words) {
            vector<int> tmp_char_number = char_number;
            char one_char;
            bool flag = true;
            for (auto one_char : word){
                if (--tmp_char_number[one_char-'a'] < 0) {
                    flag = false;
                    break;
                } 
            }
            if (flag) {
                length += word.size();
            }
        }
        return length;
    }
};
```