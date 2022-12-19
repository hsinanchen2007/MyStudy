这道题是简单的动态规划题目，但是递推方程存在许多限制，最麻烦的还是题目中对某些错误编码方式并没有提及
```
def numDecodings(s) -> int:
    l = len(s)
    nums = [0 for _ in range(l + 1)]
    nums[0] = 1
    for pos in range(l):
        if pos > 0:
            temp = int(s[pos - 1:pos + 1])
            if temp < 27 and temp > 9:
                nums[pos + 1] += nums[pos - 1]
        if s[pos]!="0":
            nums[pos + 1] += nums[pos]

    return nums[l]
```
可以看到代码里需要对当前字母是否可以组成两位编码进行判断，必须满足这个组合的两位数在10和26之间，同时，是否可以用当前数字进行编码也需要判断