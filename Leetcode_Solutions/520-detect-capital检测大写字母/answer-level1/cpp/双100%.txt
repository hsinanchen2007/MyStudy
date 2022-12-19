### 解题思路
根据第一个和第二个字母的大小写情况来判断

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int length=word.size();
        if(length==1||length==0) return true;
        if(islower(word[0]))
            for(char s : word){
                if(isupper(s))
                    return false;
            }
        if(islower(word[1])){
            for(int i=2;i<length;++i)
                if(isupper(word[i])) return false;}
        else for(int i=2;i<length;++i) if(islower(word[i])) return false;
        return true;
    }
};
```