### 解题思路
总体思路获取所有单词，然后逆序拼接成一个长字符串，去掉空格。
具体操作就是：
1. 先遍历整个原始串S，遇到非空格就保存到临时的单词word中，遇到空格，就把非空串的word放到单词vector中，这样就得到所有单词的vector。
2. 然后把单词vector逆序遍历，用空格作为分隔符，连接一个长字符串，最后去掉末尾多加的空格，就是最后结果。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ret="";
        string word="";
        vector<string> vec;
        int sSize = s.size();
        for (int i = 0; i < sSize; i++) {
            if (s[i] != ' ') {
                word.push_back(s[i]);
            }
            else {
                if (word != "") {
                   vec.push_back(word);
                   word = "";
                }
                continue;
            }
        }
        vec.push_back(word);
        for (auto ptr = vec.rbegin(); ptr != vec.rend(); ptr++) {
            if (*ptr != "") {
                ret += *ptr;
                ret += ' ';
            }
        }
        ret.pop_back();
        return ret;        
    }
};
```