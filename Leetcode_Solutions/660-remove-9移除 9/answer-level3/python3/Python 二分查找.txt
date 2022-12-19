

```
'''
数字对应的新索引号就是小于等于该数值的不包含9的数值的个数
索引号肯定和数值本身是同增同减的，所以可以用二分法搜索正确
的数值
'''

class Solution:
    # 如果val本身含9，把里面的9换成8，让数值变成比它小的最大的不含9的值
    def adjust(self, val):
        s = str(val)
        #print(s, int(''.join([ch if ch != '9' else '8' for ch in s])))
        return int(''.join([ch if ch != '9' else '8' for ch in s]))

    def getIdx(self, val: int):
        s = str(val)
        base = 1
        ans = 0
        for i in range(len(s)-1, -1, -1):
            ans += (ord(s[i]) - ord('0')) * base
            base *= 9
        return ans

    def newInteger(self, n: int) -> int:
        l, r = 1, 90000000000
        while l <= r:
            m = l + (r - l) // 2

            val = self.adjust(m)
            idx = self.getIdx(val)
            if idx == n:
                return val
            elif idx < n:
                l = m + 1
            else:
                r = m - 1
```

![image.png](https://pic.leetcode-cn.com/6a9fb5886b1ef9c12d000ce730185be1cdfd390e5d54a874f02c17419a995d7e-image.png)
