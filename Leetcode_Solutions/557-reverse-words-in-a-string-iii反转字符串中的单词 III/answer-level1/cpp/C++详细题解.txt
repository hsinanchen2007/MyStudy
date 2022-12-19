## 思路
- 遇到空格或字符串结束符，反转储存在temp内的单词，拼接到`ans`内

代码注释相对清楚，可以直接看代码

note：\0表示空字符，作为字符串结束符使用
```
class Solution {
public:
    string reverseWords(string s) {
        string ans = ""; //记录答案
        string temp = ""; //记录完整的单词
        int l = s.size();
        for(int i = 0; i <= l; ++ i) //遍历字符串
        {
            if(s[i] == ' ' || s[i] =='\0') //遇到空格或字符串结束符，反转已储存单词的temp
            {
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += s[i]; //将反转后的单词拼接到ans上，加上空格或字符串结束符
                temp = ""; //初始化temp
            }
            else
                temp += s[i]; //拼接每个字母成为完整的单词
        }
        return ans;
    }
};
```