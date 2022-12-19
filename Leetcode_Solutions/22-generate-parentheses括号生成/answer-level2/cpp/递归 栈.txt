### 解题思路
此题只需注意左括号数永远大于等于右括号，按照此规则逐个将元素放入字符串中，具体过程使用栈或者递归都可以，最后自然得到结果。
![捕获.PNG](https://pic.leetcode-cn.com/7eb04ed93914e4fcc0f96a85437dcd66f51fb0d89f8d8517b380748ae619c8e2-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    void generate(string str, vector<string>& res, int leftn, int rightn)
    {
        if(rightn == 0)
        {
            res.push_back(str);
            return;
        }
        else if(leftn == rightn)
        {
            str += '(';
            leftn--;
            generate(str, res, leftn, rightn);
        }
        else if(leftn == 0)
        {
            str += ')';
            rightn--;
            generate(str, res, leftn, rightn);
        }
        else
        {
            generate(str + '(', res, leftn - 1, rightn);
            generate(str + ')', res, leftn, rightn - 1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        generate(str, res, n, n);
        return res;
    }
};
```