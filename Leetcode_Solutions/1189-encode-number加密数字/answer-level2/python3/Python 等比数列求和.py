![image.png](https://pic.leetcode-cn.com/0206f994cfdba681686a37b680dbb5127d962bbcda588119b6f318cc84993a3f-image.png)


```
'''
等比数列求和，算出来在那个区间内，再组字符串
'''

class Solution:

    # 等比数列求和
    def total_sum(self, n):
        return (1 << n) - 1

    def encode(self, num: int) -> str:
        if num == 0:
            return ''

        num += 1
        n = 1
        while True:
            if self.total_sum(n) >= num:
                break
            n += 1

        ans = bin(num - self.total_sum(n-1) - 1)[2:]
        while len(ans) < n-1:
            ans = '0' + ans
        return ans
```
