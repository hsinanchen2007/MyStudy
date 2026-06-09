按字面要求即可，按照第一个和第二个字符确定是三种情况的哪种，然后遍历判断是否符合该种情况

代码：
```
class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if (len > 1) {
            if (word[0] >= 'a') {
                for (int i = 1; i < len; i++) {
                    if(word[i] <= 'Z')
                        return false;
                }
                return true;
            }
            else {
                if (word[1] <= 'Z') {
                    for (int i = 2; i < len; i++) {
                        if(word[i] >= 'a')
                            return false;
                    }
                    return true;
                }
                else {
                    for (int i = 2; i < len; i++) {
                        if(word[i] <= 'Z')
                            return false;
                    }
                    return true;
                }
                
            }
        }
        return true;
    }
};
```
