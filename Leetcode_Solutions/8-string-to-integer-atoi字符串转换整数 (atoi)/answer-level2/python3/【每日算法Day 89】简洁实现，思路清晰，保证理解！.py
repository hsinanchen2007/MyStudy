## 题解
官方题解用的有限状态自动机，理解起来也是比较轻松的，写起来也避免了一堆臃肿的 `if-else` 。但是我这里就不用自动机了，直接模拟就行了，写起来也很轻松好理解！

* 首先用一个变量 `idx` 标记当前遍历到的位置，用 `sign = 1, -1` 表示整数的正负性。
* 然后从 `idx = 0` 开始，将开头的空格全部去掉。

* 然后判断当前的位置 `idx` 处的字符是不是 `+, -` 或者数字，并且 `idx` 要小于字符串长度。如果一个都没满足，那么说明是非法字符串，直接返回 `0` 。

* 然后如果当前的位置 `idx` 处的字符是 `-` ，那么就令 `sign = -1` 。否则如果是 `+` ，就令 `sign = 1` 。然后遍历后一个字符。

* 最后遍历一段连续的数字，把它转换成整数，注意转换的时候要乘上符号位 `sign` 。如果发现数字超过了 `[INT_MIN, INT_MAX]` 范围，就直接返回最大最小值就行了。

* 否则的话最后就是合法整数，直接返回答案。

## 代码
### c++
```cpp
class Solution {
public:
    int myAtoi(string str) {
        int idx = 0, n = str.size();
        long res = 0, sign = 1;
        while (idx < n && str[idx] == ' ') idx++;
        if (idx >= n || (str[idx] != '+' && str[idx] != '-' && !isdigit(str[idx]))) return 0;
        if (str[idx] == '-') {
            sign = -1;
            idx++;
        } else if (str[idx] == '+') {
            idx++;
        }
        while (idx < n && isdigit(str[idx])) {
            res = res*10+sign*(str[idx++]-'0');
            if (res > INT_MAX) return INT_MAX;
            if (res < INT_MIN) return INT_MIN;
        }
        return res;
    }
};
```

### python
```python
class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.lstrip()
        n, idx = len(str), 0
        res, sign = 0, 1
        if idx >= n or (str[idx] != '+' and str[idx] != '-' and not str[idx].isdigit()): return 0
        if str[idx] == '-':
            sign = -1
            idx += 1
        elif str[idx] == '+':
            idx += 1
        for c in str[idx:]:
            if not c.isdigit(): break
            res = res*10+sign*(int(c))
            if res > 2**31-1: return 2**31-1
            if res < -2**31: return -2**31
        return res
```

### 正则表达式（python）
```python
class Solution:
    def myAtoi(self, str: str) -> int:
        return max(min(int(*re.findall('^[\+\-]?\d+', str.lstrip())), 2**31-1), -2**31)
```

> 关注公众号【算法码上来】，每日算法干货马上就来！
![宣传图片.jpg](https://pic.leetcode-cn.com/bec16294c1d0741a24675b08191a513094dd6b74b244c6f9693951ca1ca6880e-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)
