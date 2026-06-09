### 解题思路
    解题方法就是辅助栈
    若第一个为左括号则入栈,若第一个不是左括号直接返回false
    接下来就是出栈入栈操作啦!
![QQ图片20200409011817.png](https://pic.leetcode-cn.com/f9bef559fbb026bcb3949ad3d1b09f9e2fecaa52b876c2b2032814bd784f2a99-QQ%E5%9B%BE%E7%89%8720200409011817.png)

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
            return true;
        if(s.size() % 2 != 0)
            return false;

        int length = s.size();
        stack<char> sta;

        for(int i = 0;i < length;++i)
        {

            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                sta.push(s[i]);
            else
            {
                if(sta.size() == 0 && (s[i] == ']' || s[i] == ')' || s[i] == '}'))
                    return false;
                else if((sta.top() == '[' && s[i] != ']') || (sta.top() == '(' && s[i] != ')') || (sta.top() == '{' && s[i] != '}'))
                    return false;
                else
                    sta.pop();
            }

        }
        if(sta.size() == 0) return true;
        else return false;
    }
};
```