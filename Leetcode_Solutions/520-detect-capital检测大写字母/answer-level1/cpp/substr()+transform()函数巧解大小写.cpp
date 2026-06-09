通过阅读题目.我们不难得出符合条件的字符串有以下两种:
1. **全部**为大写
2. 除**第一个字母之外**,其余字母全部为小写
由此我们便可以编写以下代码:
```
class Solution {
public:
    bool detectCapitalUse(string word) {
        string str_1(word);
        string str_2 = word.substr(1, word.size());
        string str_3 = word.substr(1, word.size());
        transform(str_1.begin(), str_1.end(), str_1.begin(), ::toupper);
        transform(str_2.begin(), str_2.end(), str_2.begin(), ::tolower);
        if (word == str_1 || str_2 == str_3)
            return 1;
        else
            return 0;
    }
};
```