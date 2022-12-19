### 解题思路
此处撰写解题思路
建一个string栈，存储每次读到的单词，再出栈生成新的string即可
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> wait;
        string ans="";
        string a="";
        int m_size=s.size();
        for (int i = 0; i < m_size; i++)
        {
        while (s[i] == ' ')
        {
            i++;
        }
        if (s[i] == '\0')
        {
            break;
        }
        for (; s[i] != ' ' && i<m_size; i++)
        {
            a += s[i];
        }
        wait.push(a);
        a.clear();
        }   
        int _size=wait.size()-1;
        if(_size<0)
        {
            return ans;
        }
        ans+=wait.top();
        for(int i=0;i<_size;i++)
        {
            wait.pop();
            ans+=" ";
            ans+=wait.top();
        }
        return ans;
    }
};
```