### 解题思路
遍历，将连续重复的字符看成一个字符，然后比较两边对称的字符
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int first,last;
        int len = 0;
        int prev = 0;
        string *str = new string;

        for(int i = 0;i < n;++i)  //遍历字符串
        {
            first = last = i;  //first向前字符出发，last向后字符出发
            int temp = s[i];
            while(i < n && temp == s[i])  //出发的地方，有重复字符，调整向后出发的起点last  
            {
                last = i;
                i++;
            }
            i--;
            while(1)
            {
                first--;  last++;
                if(first < 0 || last >= n || s[first] != s[last])  //越界或两边不相等时，退出循环
                    break;
            }
            first++; last--;
            len = last - first + 1;
            if(prev < len)  //比较当前回文字符长度len和先前最大长度
            {
                prev = len;
                len = 0;
                str->clear();  //清除所有字符
                while(first <= last)
                {
                    str->push_back(s[first++]); //装入字符
                }
            }
        }
        return *str;
    }
};
```