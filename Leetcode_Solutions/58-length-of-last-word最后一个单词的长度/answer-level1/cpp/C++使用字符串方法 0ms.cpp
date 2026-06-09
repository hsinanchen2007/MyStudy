1. 当s非空时，排除s末尾所有的空格
2. 若s为空，则返回0
3. 找到s最后的一个空格，返回长度（当s中没有空格时，`s.find_last_of(' ')`返回0，仍然满足）
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        while(!s.empty() && s.back() == ' ') s.pop_back();
        if(s.empty())   return 0;
        else return s.length()-1-s.find_last_of(' ');
    }
};
```

