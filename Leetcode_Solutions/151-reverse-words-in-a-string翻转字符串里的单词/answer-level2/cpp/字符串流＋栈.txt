### 解题思路
1.先利用字符串流的输入删除所有的空格
2.利用栈的先进后出性质,完成单词的反转
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans,str;
        stack<string> tmp;
        stringstream ss(s);

        while(ss >> str)
        {
            tmp.push(str);   //将每个单词压入栈中
        }

        //每个单词出栈加一个空格,完成字符串的所有单词反转
        while(!tmp.empty())
        {
            ans += tmp.top();
            tmp.pop();
            if(!tmp.empty())
            {
                ans += " ";
            }
        }
        return ans;
    }
};
```