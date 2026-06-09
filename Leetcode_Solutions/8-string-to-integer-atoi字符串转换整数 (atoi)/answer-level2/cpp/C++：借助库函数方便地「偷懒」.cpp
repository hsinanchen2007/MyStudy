纯模拟，8ms（丢人）

首先，先了解一下string库中几个不太常用的函数：
`find_first_of` [cppreference文档页](https://zh.cppreference.com/w/cpp/string/basic_string/find_first_of) 查找给定字符序列中任意字符首次出现的位置；
`find_first_not_of` [cppreference文档页](https://zh.cppreference.com/w/cpp/string/basic_string/find_first_not_of) 查找不是给定字符序列的字符首次出现的位置；

1. 先用`find_first_of`找出第一个不是空格的位置，将字符串截取；
2. 判断第一位是符号还是数字，如果是数字，neg_flag为0，如果是负号，则为-1，如果是正号，则为1；
3. 使用`find_first_not_of`找出从abs(neg_flag)位置开始第一个不是数字的位置，截取；
4. 进入数字还原的步骤，如果途中超出了INT_MAX，则根据正负提前返回对应的值，否则继续；
5. 最后返回结果乘以正负标记即可（记得如果neg_flag为0先将其置为1）

```
class Solution {
   public:
    int myAtoi(string str) {
        // 去掉前多余空白
        size_t pos_begin = str.find_first_not_of(" ");
        if (pos_begin != string::npos) {
            str = str.substr(pos_begin);
        }

        // 判断有无符号
        int neg_flag = 0;
        if (str[0] == '-') {
            neg_flag = -1;
        } else if (str[0] == '+') {
            neg_flag = 1;
        }

        // 查找第一个不是数字的位置 将其截掉
        size_t pos_end = str.find_first_not_of("0123456789", abs(neg_flag));
        str = str.substr(abs(neg_flag), pos_end - abs(neg_flag));
        if (neg_flag == 0) neg_flag = 1;

        // 还原为数字
        long long ans = 0;
        for (char c : str) {
            ans = ans * 10 + c - '0';
            if (ans > INT_MAX) {
                return neg_flag == -1 ? INT_MIN : INT_MAX;
            }
        }

        return (int)ans * neg_flag;
    }
};
```
