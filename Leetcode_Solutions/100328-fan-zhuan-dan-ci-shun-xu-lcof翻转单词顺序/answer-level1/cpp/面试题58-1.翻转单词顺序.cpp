### 解题思路
- 由于只需要翻转单词，考虑从后往前处理字符串。
- 字符串首尾的空格在最后输出的时候不需要，可以去掉。
- 注意，在去掉空格的过程中，用到了
`s.erase(s.find_last_not_of(" ")+1);`
需要解释的是，`s.find_last_not_of(" ");`返回的是int下标，而`erass(int n)`表示从n开始到尾部的都删了，`erase(iterator pos)`则表示删除pos位置的单个元素。
- 从尾部开始，需要一个计数器计算有多少非空格字符，然后检测出一个单词就`substr`取出子串，`+=`拼接起来。
- 注意处理检测到字符串头的特殊情况。


### C++代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        //特殊
        if(s.empty())
            return "";
        else
        {
            s.erase(0,s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ")+1);
        }
        //功能
        string ans;
        int len = 0;
        for(int i = s.length()-1;i >= 0;i--)
        {
            if(s[i] != ' ')
            {
                len++;
            }
            else if(s[i] == ' '&& len != 0 )
            {
                ans += s.substr(i+1,len) + " ";
                len = 0;
            }

            if(i == 0 && len != 0 )
            {
                ans += s.substr(i,len);
            }
        }
        if(ans.empty())
            return "";
        else
        {
            ans.erase(ans.find_last_not_of(" ")+1);
            return ans;
        }
    }
};
```