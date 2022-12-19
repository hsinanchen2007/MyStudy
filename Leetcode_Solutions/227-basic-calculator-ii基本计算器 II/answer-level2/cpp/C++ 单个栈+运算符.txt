### 解题思路
与基本计算器Ⅰ类似，先去除空格再进行栈+运算符计算

### 代码

```cpp
/*
符号栈用一个变量sign代替了，只存储上一个符号，主要思想如下：
将减法转化为加法（取相反数）
由于乘除法优先级高，直接计算
整数不仅一位，会>10
表达式中没有括号

注意：
加减乘除空格的ASCII码都小于'0'，ASCII对照表如下：http://tool.oschina.net/commons?type=4
先做减法，避免int溢出
char类型，不能使用switch
*/
class Solution {
public:
    int calculate(string s) {
        //先去除字符串中所有的空格
        int index = 0;
        if( !s.empty())
        {
            while( (index = s.find(' ',index)) != string::npos)
            {
                s.erase(index,1);
            }
        }

        //栈+对运算符号优先级进行判断并运算
        int res = 0, d = 0;
        char sign = '+';
        stack<int> nums;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0') {          //加减乘除和空格ASCII码都小于'0'
                d = d * 10 - '0' + s[i];//进位(先减法)
            }
            if (s[i] < '0' || i == s.size() - 1) {
                if (sign == '+') {
                    nums.push(d);
                } else if (sign == '-') {
                    nums.push(-d);
                } else if (sign == '*' || sign == '/') {
                    int tmp = sign == '*' ? nums.top() * d : nums.top() / d;
                    nums.pop();
                    nums.push(tmp);
                }
                sign = s[i];            //保存当前符号
                d = 0;
            }
        }
        for (; !nums.empty(); nums.pop()) {
            res += nums.top();
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6ef923b75677eadaf9e5d61650af53112ac87f8b200516b0ea98ec1c8f42be34-image.png)
