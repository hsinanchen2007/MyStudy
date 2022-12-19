### 解题思路
以2105为例
千位为1的数：
    如果千位大于1，则千位为1的数有1000~1999，
    如果等于1，则千位为1的数就等于除开千位后面的数，如1130，则千位为的数是1000~1130
百位为1的数：
    百位为1的数有：01xx,11xx,21xx， 共两次加21xx一部分(2100~2105)
十位为1的数：
    十位为1的数有：001x, 011x, ..., 201x 共重复21次(21xx不算，因为当前十位为0）

所以可以将每一位的数分为三类处理：当前位大于1，等于1，小于1

### 代码

```python3
class Solution:
    def countDigitOne(self, n: int) -> int:
        s = str(n)
        length = len(s)
        count = 0
        for i in range(length):
            if i == 0:
                res = 1
            else:
                res = int(s[:i])+1
            
            if int(s[i]) == 1:
                if i < length-1:
                    count += int(s[i+1:])+1
                else:
                    count += 1
                count += (res-1) * 10**(length-i-1)
            elif int(s[i]) == 0:
                count += (res-1) * 10**(length-i-1)
            else:
                count += res * 10**(length-i-1)
            # print(count)
        return count
```