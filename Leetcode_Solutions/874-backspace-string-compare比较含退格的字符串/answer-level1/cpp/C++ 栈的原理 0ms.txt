### 解题思路
用两个栈，不断添加字符，遇上#就删除尾部字符，最后对比两个栈是否相同
![image.png](https://pic.leetcode-cn.com/0dc4b8ec48b9fd9825b9638088cd9bf51ea90d8a6e18b47133096f0f8d4be786-image.png)


### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T)
    {
        string stack1 = "", stack2 = "";
        for (auto s : S)
            if (s == '#' && stack1 != "")
                stack1.pop_back();
            else if (s != '#') stack1.push_back(s);
        for (auto t : T)
            if (t == '#' && stack2 != "")
                stack2.pop_back();
            else if (t != '#') stack2.push_back(t);
        return stack1 == stack2;
    }
};
```