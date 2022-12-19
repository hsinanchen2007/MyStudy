### 解题思路
分而治之，先写函数say，传入一个字符串作为n-1，输出n作为n-1的描述结果；
再递归。n的n次方时间复杂度。。。

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        return self.say(self.countAndSay(n - 1))

    def say(self, s: str) -> str:
        count = 0
        tstr = s[0]
        res = ""
        i = 0
        while i < len(s):
            if s[i] == tstr:
                count += 1
            else:
                res = res + str(count) + tstr
                tstr = s[i]
                count = 1

            if i == len(s) - 1:
                res = res + str(count) + tstr

            i += 1

        return res
```
slt = Solution()
for x in range(1, 31):
    nin = x
    print("x = %d, result = %s" %(x, slt.countAndSay(nin)))
#print(slt.say("1211"))