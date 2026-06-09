### 方法一：迭代
1. 先去除输入字符两边的空格，将剩下部分保存在数组中（如果数组为空返回 $0$）；
2. 根据第一位是否为负号初始化负号标识位 `flag`；
3. 删去首尾的符号并利用 ASCII 码计算数字部分。

注：计算方法如下
$$int('2')=ord('2')-ord('0')=50-48=2$$
### 代码

```python []
class Solution:
    def strToInt(self, str: str) -> int:
        ls = list(str.strip())
        if not ls: return 0
        flag = -1 if ls[0] == '-' else 1
        if ls[0] in ['+', '-']: del ls[0]
        ret, i = 0, 0
        while i < len(ls) and ls[i].isdigit():
            ret = ret * 10 + ord(ls[i]) - ord('0')
            i += 1
        return max(-2 ** 31, min(2 ** 31 - 1, flag * ret)) # 防止溢出
```
```C++ []
class Solution {
public:
    int strToInt(string str) {
        if (str.empty()) return 0;
        int i = 0, sign = 1;
        while (i + 1 < str.size() && isspace(str[i])) ++i; 
        long res = 0;
        if (str[i] == '-' || str[i] == '+') 
            sign = 44 - str[i++];  // +:43,-:45;str[i++]:str[i],i++
        while (i < str.size()) {
            if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
            else return res * sign;
            if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
        }
        return res * sign;
    }
};
```

### 方法二：正则表达式
也可以使用正则表达式来匹配：
- `^`：匹配字符串开头
- `[\+\-]`：代表一个+字符或-字符
- `?`：前面一个字符可有可无
- `\d`：一个数字
- `+`：前面一个字符的一个或多个

```python []
class Solution:
    def strToInt(self, str: str) -> int:
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        s= str.strip()
        res = re.compile(r'^[\+\-]?\d+')
        num = res.findall(s)
        nums = int(*num)
        return max(min(nums, INT_MAX), INT_MIN)
```