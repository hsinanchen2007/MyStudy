### 解题思路
1.对遍历出每个字符
2.判断首字符是否为‘-’或‘+’或0-9，用一个标志start确定是否为首字母。用flag标志整数的正负。
3.用来承载累加数据的变量定义为long.
4.注意边界判断，大于或小于边界就返回。

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0||str == " ") return 0;
        int flag = 1;
        bool start = false;//是否已经开始
        long res = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' '&&start == false) {
                continue;
            }
            if (str[i] == '+'&&start == false) {
                start = true;
                continue;
            }
            if (str[i] == '-'&&start == false) {
                start = true;
                flag = -1;
                continue;
            }
            if (str[i] >= '0'&&str[i] <= '9') {
                start = true;
                res = res * 10 + (str[i] - 48);
                if (flag*res > INT_MAX) {
                    return INT_MAX;
                }
                if(flag*res < INT_MIN) {
                    return INT_MIN;
                }

            }
            else {
                break;
            }
        }
        return flag*res;
        }
};
```