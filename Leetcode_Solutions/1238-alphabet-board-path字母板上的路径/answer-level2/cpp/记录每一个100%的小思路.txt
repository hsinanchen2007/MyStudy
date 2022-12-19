### 解题思路
执行用时8 ms,击败了24.26%
内存消耗8.5 MB,击败了100.00%
思路其实比较简单，记录每个字母的位置，把行数和列数计算出来
有一个坑，就是z那里，如果要去z，只能先左右再上下，从z出来，只能先上下再左右
我就是在这里判断了一下

### 代码

```cpp
class Solution 
{
public:
    string alphabetBoardPath(string target) 
    {
        char tmp = 'a';
        string result="";
        for (int i = 0; i < target.size(); i++)
        {
            if(target[i]=='z' && tmp!='z')
            {
                int rows = (target[i]-'a')/5 - (tmp-'a')/5; // 第几行
                int cols = (target[i]-'a')%5 - (tmp-'a')%5; // 第几列
                while (cols > 0)
                {
                    result+='R';
                    cols--;
                }
                while (cols < 0)
                {
                    result+='L';
                    cols++;
                }
                while (rows > 0)
                {
                    result+='D';
                    rows--;
                }
                while (rows < 0)
                {
                    result+='U';
                    rows++;
                }
            }
            if (target[i]!='z' && tmp=='z')     
            {
                int rows = (target[i]-'a')/5 - (tmp-'a')/5; // 第几行
                int cols = (target[i]-'a')%5 - (tmp-'a')%5; // 第几列
                while (rows > 0)
                {
                    result+='D';
                    rows--;
                }
                while (rows < 0)
                {
                    result+='U';
                    rows++;
                }
                while (cols > 0)
                {
                    result+='R';
                    cols--;
                }
                while (cols < 0)
                {
                    result+='L';
                    cols++;
                }
            }
            if (target[i]!='z' && tmp!='z')
            {
                int rows = (target[i]-'a')/5 - (tmp-'a')/5; // 第几行
                int cols = (target[i]-'a')%5 - (tmp-'a')%5; // 第几列
                while (rows > 0)
                {
                    result+='D';
                    rows--;
                }
                while (rows < 0)
                {
                    result+='U';
                    rows++;
                }
                while (cols > 0)
                {
                    result+='R';
                    cols--;
                }
                while (cols < 0)
                {
                    result+='L';
                    cols++;
                }
            }
            tmp = target[i];
            result+='!';
        }
        return result;
    }
};
```