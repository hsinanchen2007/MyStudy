# 两个坑点：

1.abbr含有**01**这样的是非法的
2.遍历完了abbr，要检查word是否**到头**了

```
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pos = 0;
        for (int i = 0; i < abbr.size(); i++) {
            if (!isdigit(abbr[i])) {
                if (abbr[i] != word[pos++]) {                    
                    return false;
                }
            } else if (abbr[i] == '0') {
                return false;
            } else {
                int j = i + 1;
                while (isdigit(abbr[j])) {
                    j++;
                }
                pos+=stoi(abbr.substr(i, j - i));
                if (pos > word.size()) {
                    return false;
                }
                i = j - 1;
            }
        }
        return pos >= word.size();
    }
};
```
