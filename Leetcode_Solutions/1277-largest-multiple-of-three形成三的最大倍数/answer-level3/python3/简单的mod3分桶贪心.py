### 解题思路
简单的mod3分桶贪心
### 代码

```python3
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        d0 = [num for num in digits if num%3 == 0]
        d1 = [num for num in digits if num%3 == 1]
        d2 = [num for num in digits if num%3 == 2]

        cnt12 = min(len(d1), len(d2))
        cnt1 = (len(d1) - cnt12) % 3 
        cnt2 = (len(d2) - cnt12) % 3
        r1 = 0
        r2 = 0
        if cnt1 == 0 and cnt2 == 2:
            if len(d1) > 0:
                r1 = 1
            else:
                r2 = 2
        if cnt1 == 0 and cnt2 == 1:
            r2 = 1
        if cnt2 == 0 and cnt1 == 2:
            if len(d2) > 0:
                r2 = 1
            else:
                r1 = 2
        if cnt2 == 0 and cnt1 == 1:
            r1 = 1

        d1, d2 = sorted(d1), sorted(d2)
        d1, d2 = d1[r1:], d2[r2:]
        ans = d0 + d1 + d2
        ans = sorted(ans)
        s = ''
        for i in ans[::-1]:
            s += str(i)
        if len(s) > 0 and s[0]=='0':
            return '0'
        return s
        



```