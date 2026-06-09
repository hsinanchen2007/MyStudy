### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   bool detectCapitalUse(string word) {
    if (word[0]>='A'&&word[0]<='Z') {
        if (word[1]>='A'&&word[1]<='Z') {
            for (int i=2; i<word.length(); i++) {
                if (word[i]<'A'||word[i]>'Z') {
                    return false;
                }
            }
            return true;
        }
        else{
            for (int i=2; i<word.length(); i++) {
                if (word[i]>='A'&&word[i]<='Z') {
                    return false;
                }
            }
            return true;
        }
    }
    else if(word[0]<='z'&&word[0]>='a'){
        for (int i=1; i<word.length(); i++) {
            if (word[i]>='A'&&word[i]<='Z') {
                return false;
            }
        }
        return true;
    }
    return false;
}
};
```