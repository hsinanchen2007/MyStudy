### 解题思路
先把 int 转成二进制串，python 内置的 bin 函数，转出来的字符串是以 0b 开头，所以用 [2:] 去掉 0b。

然后用 [::-1] 把二进制串反转过来，便于对齐处理。这时候从下标 0 开始，一位一位的比较 a、b、c。

如果 c 是 0：

如果 a 这一位是 1，操作数加 1
如果 b 这一位是 1，操作数加 1
如果 c 是 1：

​ 如果 a 和 b 这一位都是 0 操作数加 1

### 代码

```python3
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        def to_binary_str(num):
            return bin(num)[2:] # bin(b) -> '0b110'
        a2 = to_binary_str(a)[::-1] # reverse str
        b2 = to_binary_str(b)[::-1]
        c2 = to_binary_str(c)[::-1]
        cnt = 0
        for i in range(len(c2)):
            if c2[i] == '0':
                if len(a2) > i and a2[i] == '1':
                    cnt += 1
                if len(b2) > i and b2[i] == '1':
                    cnt += 1
            if c2[i] == '1':
                if (len(a2) <= i or a2[i] == '0') and (len(b2) <= i or b2[i] == '0'):
                    cnt += 1
        for i in range(len(c2), max(len(a2), len(b2))):
            if len(a2) > i and a2[i] == '1':
                cnt += 1
            if len(b2) > i and b2[i] == '1':
                cnt += 1
        return cnt
```

[我的博客上的解答](https://codeplot.top/2020/01/12/leetcode-%E5%91%A8%E8%B5%9B-171-5308-%E6%88%96%E8%BF%90%E7%AE%97%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BF%BB%E8%BD%AC%E6%AC%A1%E6%95%B0-Minimum-Flips-to-Make-a-OR-b-Equal-to-c/)