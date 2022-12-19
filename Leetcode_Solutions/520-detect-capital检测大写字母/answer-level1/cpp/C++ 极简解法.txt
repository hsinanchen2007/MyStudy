其实只要记录有多少个大写字母即可，在遍历过程中，如果大写字母的个数小于正在遍历的下标，说明不符合题解，既不是连续的出现大写字母，如 “Aa**A**a” 遍历到第二个 A 时的情况。

最终判断是否为全大写或只是首字母大写即可。

```cpp []
class Solution {
public:
    bool detectCapitalUse(string word) {
        int uc = 0;
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i]) && uc++ < i) {
                return false;
            }
        }
        
        return uc == word.size() || uc <= 1;
    }
};
```