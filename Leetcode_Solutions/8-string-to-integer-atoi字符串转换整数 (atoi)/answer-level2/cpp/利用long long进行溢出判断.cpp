### 解题思路
此处撰写解题思路
![QQ截图20200403173711.png](https://pic.leetcode-cn.com/87bed4005bfdb0e53e93b8e0f31b0f5df16810f0cc42cf320f2f0b5d39597d72-QQ%E6%88%AA%E5%9B%BE20200403173711.png)
首先ans不定义为int，定义为long long，有利于溢出判定；
遇到空格就往后跳，直到跳到第一个+或者-或者数字；
根据三者不同的规则进行将字符串转换为数字；
中间过程中一旦超过int的范围马上返还int边界值；
官方解题的DFA解析图思维上更加完善，这个解题相当于只考虑到能转化的状态。
### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        long long ans=0;
        int i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == 43) {
            i++;
            while (str[i] >= 48 && str[i] <= 57) {
                ans = ans * 10 + str[i] - 48;
                if (ans >= INT_MAX) return INT_MAX;
                i++;
            }
        }
        else if (str[i] == 45) {
            i++;
            while (str[i] >= 48 && str[i] <= 57) {
                ans = ans * 10 - (str[i] - 48);
                if (ans <= INT_MIN) return INT_MIN;
                i++;
            }
        }
        else if (str[i] >= 48 && str[i] <= 57) {
            while (str[i] >= 48 && str[i] <= 57) {
                ans = ans * 10 + str[i] - 48;
                if (ans >= INT_MAX) return INT_MAX;
                i++;
            }
        }
        return (int)ans;
    }
};
```