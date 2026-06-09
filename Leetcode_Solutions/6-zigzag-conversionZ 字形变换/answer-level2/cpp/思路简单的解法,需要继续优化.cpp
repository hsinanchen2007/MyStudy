### 解题思路
此处撰写解题思路
把数据分别存入各行中,逐行写入,然后最后合并起来
例如
LEETCODEISHIRING
各行的数据是
1 2 3 4 ...
L D     
E O E
E C I 
T   S
类似上面的方式逐个字符,遇到 第0行开始增加行数,遇到(numRows-1)行开始递减行数,循环把所有数据写入到各行中,然后合并起来
### 代码

```cpp
class Solution {
public:
string convert(string s, int numRows) 
{
    if (s.length()<=1 || numRows<=1)
    {
        return s;
    }
    string strBuf = s;
    string strRet;
    string* strRows = new string[numRows];
    int j = 0 ;
    bool bFlag = true;
    for (int i = 0;i<strBuf.length();i++)
    {
        if (j==(numRows-1) )
        {
            bFlag = false;   
        }
        if (j==0)
        {
            bFlag=true;
        }
        strRows[j]+=strBuf[i];
       
        bFlag?++j:--j;
        
    }
    for (int n = 0;n<numRows;n++)
    {
        strRet+=strRows[n];
    }
    return strRet;
}
};
```