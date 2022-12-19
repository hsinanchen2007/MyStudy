## 思路
- 由于单词本身不变，只反转单词的顺序，因此将每个单词看作一个整体，使用`temp`收集完整的单词后压入栈`mid`内
- 使用栈先入先出的数据结构，实现单词顺序的反转
## 详细步骤
1. 删除字符串前的空格，若字符串全是由空格组成，该步骤结束后字符串`s`为空
2. 若字符串`s`为空，直接返回空字符串
3. 遍历当前字符串内的所有字符，当遇到空格，若`temp`里面有单词，压入栈`mid`，`temp`初始化；当遇到字母，先加到`temp`内，使他成为一个完整的单词
4. 遍历结束后将栈内的单词放入`ans`，加上单词间的空格。手动添加最后一个单词，因为之前添加单词时，会在末位添加空格，最后一个不需要空格
note: \0表示空字符，作为字符串结束符使用
```
class Solution {
public:
    string reverseWords(string s) {
        string ans = ""; //用来储存答案
        stack <string> mid; //记录所有单词
        string temp = ""; //收集完整的单词
        int i = 0;
        while (s[0] == ' ')  //删除字符串前的空格，可以用来检测整个字符串是否都是空格
        {
            s.erase(0,1);
        }
        if(s.empty())  return ans; //若s为空，不需要处理，直接返回空字符串
        int l = s.size();
        while(i <= l) //遍历当前字符串内的所有字符
        {
            if(s[i] == ' ' || s[i] == '\0') //当遇到空格或'\0'，若temp里面有单词，压入栈mid
            {
                if(!temp.empty())
                {
                    mid.push(temp);
                    temp = "";
                }
            }
            else //若遇到字母，先加到temp内，使他成为一个完整的单词
            {
                temp = temp + s[i];
            }
            ++ i;
        }
        int strsize = mid.size();
        for(int j = 0; j < strsize - 1; ++ j) //将栈内的单词放入ans，加上单词间的空格
        {
            ans = ans + mid.top() + ' ';
            mid.pop();
        }
        ans = ans + mid.top(); //手动添加最后一个单词，因为之前添加单词时，会在末位添加空格。最后一个不需要空格
        return ans;
    }
};
```