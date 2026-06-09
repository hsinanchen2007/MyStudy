写下前几个，就能看出规律了。

n=1: res=10

n=2: res=9*9+10=91  # 两位数第一位只能为1-9，第二位只能为非第一位的数，加上一位数的所有结果

n=3: res=9 * 9 * 8+91=739  # 三位数第一位只能为1-9，第二位只能为非第一位的数，第三位只能为非前两位的数，加上两位数的所有结果

n=4: res=9 * 9 * 8 * 7+739=5275  # 同上推法

因此，代码如下

```python
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if not n:
            return 1
        res, muls = 10, 9
        for i in range(1, min(n,10)):
            muls *= 10 - i
            res += muls
        return res
```