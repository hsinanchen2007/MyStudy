### 解题思路

双指针遍历

### 代码

```cpp
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; // 第一个字符串位置
        int j = 0; // 第二个字符串位置
        while (j < abbr.size()){
            if (isalpha(abbr[j]) ){
                if (word[i] != abbr[j]){
                    return false;
                }
                i++;
                j++;
            } else {
                if (abbr[j] == '0'){ // 第一个数字是0
                    return false;
                }
                int e = j+1;
                while (isdigit(abbr[e]) && e <abbr.size() ){
                    e++;
                }
                
                i = i + atoi(abbr.substr(j, e-j).c_str());
                j = e;
            }
        }
     
        return j == abbr.size() && i == word.size();
    }
};
```

![408.ac.valid-word-abbreviation](https://pic.leetcode-cn.com/b5b1697e966a54380fc56270ee0ed776d455b71960ca808ef7b9e0710e5e9e75-file_1578383503257)