### 解题思路
去除所有的空格，取出所有的单词

### 代码

```cpp
class Solution {
    string reverseWords(string &s,int &i)
    {
        int begin=i;

        while(s[i]!=' '&&i<s.length())  //取出单词
            i++;

        int end=i;

        while(s[i]==' '&&i<s.length())  //去除空格
            i++;

        return i<s.length()?(reverseWords(s,i)+" "+s.substr(begin,end-begin)):s.substr(begin,end-begin);

    }
public:
    string reverseWords(string s) {
        int i=0;
        while(s[i]==' '&&i<s.length())  //如果开头有空格，去除空格
            i++;
        return reverseWords(s,i);
    }
};
```