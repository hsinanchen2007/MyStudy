### 解题思路
两种情况：
1. "aA***" 类：第一个为小写，第二个为大写，返回false
2. 从第二个字母开始遍历并统计大写个数：
    （1）大写为0个，例“Abbbbbb”,则为true
    （2）大写为长度-1，例“ABCDEFG”，则为true

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        if( islower(word[0]) && isupper(word[1]) )  return false;
        int upCount = 0;
        for(int i = 1; i < word.length(); i++)
            if(word[i] >= 65 && word[i]<= 92)
                upCount++;
        if(upCount==0 || upCount==word.length()-1) return true;
        else return false;
    }
};
```