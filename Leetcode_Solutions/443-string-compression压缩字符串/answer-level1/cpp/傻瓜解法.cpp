### 解题思路
题目让修改的是输入数组，那只需要将最终字符串保存string容器内，再用将输入数组清空，最后将string容器内元素按顺序插入输入数组就好了。
获取最终字符串的方法：
    1）先获取输入数组倒数第一位字符作为标记符号ch，并把字符数num定为1.（其实一开始的标记符号是数组第一位字符也是可以的，只需将后面遍历的顺序反转而已）
    2）从数组倒数第二字符开始，从尾到头遍历输入数组。若当前字符与ch相等，num加一。若当前字符与ch不相等，说明与ch相同的字符已经遍历过了，将该字符ch与字符数num插入字符串str尾部，并将标记符号ch定义为当前字符，num归一。

### 代码

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        
        string str="";
        char ch=chars[chars.size()-1];
        int num=1;
        
        for(int i=chars.size()-2;i>=0;i--)
        {
            if(ch!=chars[i])
            {
                if(num==1)
                {
                    str=ch+str;
                }
                else
                {
                    str=ch+to_string(num)+str;
                }
                
                ch=chars[i];
                num=1;
            }
            else
            {
                num++;
            }
        }
        
        if(num==1)
        {
            str=ch+str;
        }
        else
        {
            str=ch+to_string(num)+str;
        }
        
        chars.clear();
        
        for(int j=0;j<str.size();j++)
        {
            chars.push_back(str[j]);
        }
        
        return chars.size();

    }
};
```