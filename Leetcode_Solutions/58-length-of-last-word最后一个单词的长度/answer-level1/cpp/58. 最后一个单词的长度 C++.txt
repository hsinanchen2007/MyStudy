### 解题思路
1.两个指针，start与end，先用end定位到最后一个单词最后一个字符，再用start定位到最后一个单词的前一个空格。
2.至此end与start差值就为定位的最后一个单词的长度值。

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while( end >= 0 && s.at(end) == ' '){
            end--;
        }
        
        if(end < 0) return 0;
        int start = end;
        while(start >= 0 && s.at(start) != ' '){
            start--;
        }
        return end - start;
    }
};
```