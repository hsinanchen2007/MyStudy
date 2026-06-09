### 解题思路
这道题小坑比较多，但是只考虑整数，不用考虑小数，又简单了不少。
1. 开头空格都去掉
2. 第一个非空字符如果是‘-’/‘+’，则记录下正负，sign=-1/1
3. 最后就是处理边界问题，先处理边界再计算，这样可以避免越界，虽然python没有越界这个盖面

### 代码

```python
class Solution:
    INT_MAX = 2**31 - 1
    INT_MIN = -2**31
    def myAtoi(self, str: str) -> int:
        if not str:
            return 0
        # 去掉空格
        str = str.strip()
        size = len(str)
        i = 0
        res = 0
        sign = 1
        # 首字符决定正负号
        if i < size and (str[i] == '+' or str[i] == '-'):
            sign = 1 if str[i] == '+' else -1
            i += 1
        while i < size and ('0' <= str[i] <= '9'):
            # 先处理越界，并取10整除，因为先判断越界再做后面运算，所以要判断是否超过最大值的整除10的数
            # res > self.INT_MAX // 10 对应最小边界
            # res == self.INT_MAX // 10 and (ord(str[i]) - ord('0') > 7) 对应最大边界, 这里7是因为(2**31 - 1) % 10 = 7
            if res > self.INT_MAX // 10 or (res == self.INT_MAX // 10 and (ord(str[i]) - ord('0') > 7)):
                if sign == 1:
                    return self.INT_MAX
                else:
                    return self.INT_MIN
            res = res * 10 + ord(str[i]) - ord('0')
            i += 1
        return res * sign


```