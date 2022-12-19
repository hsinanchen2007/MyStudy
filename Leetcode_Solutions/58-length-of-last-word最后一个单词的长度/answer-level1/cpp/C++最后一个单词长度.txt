执行时击败了C++94%的用户，方法：step1.翻转字符串更加直观 step2.以空格' '为标识 step3.注意不以空格间隔最后一个单词的情况，如字符串原本就只有一个单词、字符串以空格结尾等。
```
#include <algorithm>
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        int begin = 0;
        if(s.find(' ', 0)==-1) return n;
        while(s[begin]==' ') ++begin;
        if (begin == n) return 0;
        int endindex = s.find(' ', begin)!=-1?s.find(' ', begin):n;
        return endindex-begin;
    }
};
```

