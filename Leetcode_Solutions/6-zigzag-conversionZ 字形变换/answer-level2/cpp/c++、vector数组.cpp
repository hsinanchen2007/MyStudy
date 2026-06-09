### 解题思路
观察发现，可以用一个数组储存一行字符，由于字符数量不定故使用vector数组；本题使用的是二维vector数组。可以利用一个flag标签来判断字符放在哪个vector数组，详细介绍见代码注释。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
       if(s.length() <= numRows || numRows == 1)  //字符串长度小于等于行数及行数为1时直接返回原字符串
       return s;
       vector<char> ans(numRows);  //创建二维数组
       int i = 0, j = 0, flag = -1;
       while(i < s.length())
       {
           ans[j].push_back(s[i]);
           i ++;
           j += flag*(-1);
           if(j == 0 || j == numRows - 1)  //当j为0或numRows时改变flag标签
               flag *= -1;
       }
       string ss = "";
       for(int i = 0 ;i < numRows; i++)
          for(int j = 0; j < ans[i].size(); j++)
            ss += ans[i][j];
        return ss;
    }
};
```