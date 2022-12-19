### 解题思路
此处撰写解题思路
用时：100% 内存：75%
先把字符串倒过来，补全相同长度，添加进位标志保存上一次的进位，模拟加法过程，最后添加最高位，最后把字符串倒回来。
### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() == 0) {
            return num2;
        }
        if (num2.size() == 0) {
            return num1;
        }
        string str;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num1.size() > num2.size()) {
            while (num1.size() != num2.size()) {
                num2.push_back('0');
            }
        }
        if (num1.size() < num2.size()) {
            while (num1.size() != num2.size()) {
                num1.push_back('0');
            }
        }
        int flag = 0;
        for (int i = 0; i < num1.size(); i++) {
            int temp = num1[i] - '0' + num2[i] - '0' + flag;
            if (temp >= 10) {
                temp %= 10;
                str.push_back(temp + '0');
                flag = 1;
            } else {
                str.push_back(temp + '0');
                flag = 0;
            }
        }
        if (flag == 1) {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
```