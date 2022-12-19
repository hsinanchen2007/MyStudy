### 解题思路
首先删除末尾的所有空格，再用string类的rfind函数寻找最后一个空格后的单词，如果没有空格则整体为最后一个单词。

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==' ') s.erase(i, 1);
            else break;
        }
        if(s.length()==0) return 0;
        int lastWordPos = s.rfind(" ");
        if(lastWordPos == s.length()) return s.length();
        return s.substr(lastWordPos+1).length();
    }
};
```