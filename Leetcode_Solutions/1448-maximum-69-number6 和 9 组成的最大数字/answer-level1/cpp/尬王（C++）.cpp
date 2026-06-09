### 解题思路
此处撰写解题思路
这题比较简单，就分享一下字符串转数字和数字转字符串的方法吧。
### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        return atoi(s.c_str());
    }
};
```