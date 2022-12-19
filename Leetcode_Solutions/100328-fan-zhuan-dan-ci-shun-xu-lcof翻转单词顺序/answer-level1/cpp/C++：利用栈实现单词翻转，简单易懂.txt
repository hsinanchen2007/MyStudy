### 解题思路
（1）每次取出一个单词存入栈中；
（2）每次返回栈顶元素，并添加到输出字符串res后，然后删除当前的栈顶元素。
【注意】：
（1）需要考虑字符串为空或者字符串全部为空格的边界条件；
（2）注意每个单词后空格的添加，并且需要将输出字符串res末尾多余的空格删除。

### 代码

```cpp
class Solution 
{
public:
    string reverseWords(string s) 
    {
        if (s.empty())  //如果字符串为空即""
        {
            return s;
        }
        int blank_count;  //统计字符串中的空格数
        for (int i=0;i!=s.size();i++)
        {
            if (s[i]==' ')
            {
                blank_count++;
            }
        }
        if (blank_count==s.size())  //如果字符串中全为空格
        {
            return "";
        }
        stack<string>temp;  //放入取出的单词
        string res;  //最终的输出字符串
        string word;  //临时保存每次取出的字符串
        for (int i=0;i<=s.size();i++)  //s[s.size()]='\0'
        {
            if (s[i]==' ' || s[i]=='\0')
            {
                if (!word.empty())  //如果字符串以' '开始，此时word为空，不需要放入栈中
                {
                    temp.push(word);
                    word="";
                }
            }
            else
            {
                word+=s[i];
            }
        }
        while (!temp.empty())  //依次将栈顶元素添加到res后
        {
            res+=temp.top()+" ";
            temp.pop();
        }
        res.erase(res.size()-1,1);  //删除最后一个空格
        return res;
    }
};
```