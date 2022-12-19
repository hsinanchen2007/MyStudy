### 解题思路
一个字，栈
三个字，模拟栈

![image.png](https://pic.leetcode-cn.com/519a2c331f0c2f92282cd2fc9ca899fdfb1a9fd9a6893f01e3c82775e318869d-image.png)


### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        int len = s.length(), tmp;
        // hp 用 vector 模拟栈
        vector<char> hp;
        for(int i = 0; i < len; i++)
            // 入栈
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                hp.push_back(s[i]);
            else
            {
                // 栈为空
                if(hp.size() == 0) return false;
                // 取栈顶元素
                tmp = hp.back();
                // 出栈
                if(tmp == '(' && s[i] == ')' || tmp == '[' && s[i] == ']' || tmp == '{' && s[i] == '}')
                hp.pop_back();
                else
                    return false;
            }
        // 判定栈是否为空
        return (hp.size() == 0);
    }
};
```