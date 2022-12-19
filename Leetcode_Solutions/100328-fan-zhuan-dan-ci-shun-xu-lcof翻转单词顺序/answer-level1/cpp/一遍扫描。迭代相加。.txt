### 解题思路
双指针扫描。
i(left)确定左边的界限
j(right)确定右边的界限。
一遍扫面。
然后字符串迭代相加。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
       string strs;
        size_t i = 0;
        while (i < s.size())
        {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] != ' ')//右界确定
            {
                size_t j = i;
                while ((s[j] != ' ')&&j<s.size())j++;//左界确定
                string str = s.substr(i, j - i);//获取子串
                if (strs == "")strs = str + strs;//迭代相加。注意空格的处理。
                else strs = str + " " + strs;
                i = j+1;//指针位置变更。
            }
        }    
        return strs;

    }
};
```