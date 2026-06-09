### 解题思路
使用一个差值数组sub来存储A中后一个元素与前一个元素之差，sub中只要连续两个或以上值相同，即可构成等差数列，遍历sub数组，用count计数连续相等的差值数，最后ans += count*(count-1)/2

### 代码

```python
class Solution(object):
    def numberOfArithmeticSlices(self, A):
        if len(A) < 3:
            return 0
        sub = [0] * (len(A) - 1)
        count = 1
        ans = 0
        for i in range(1,len(A)):
            sub[i-1] = A[i] - A[i-1]
        l = 0
        r = 1
        while l < len(sub) and r < len(sub):
            if sub[r] == sub[l]:
                count += 1
                r += 1
            else:
                ans += int(count*(count-1)/2)
                l = r
                r += 1
                count = 1
            if r == len(sub):
                ans += int(count*(count-1)/2)
        return ans

```