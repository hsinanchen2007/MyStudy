```
class Solution(object):
    def kConcatenationMaxSum(self, arr, k):
        mod = 10**9 + 7
        pre, ans = 0, 0
        for a in (arr if k== 1 else arr*2):
            pre = max(a, pre+a)
            ans = max(ans, pre)
        # 当一个周期的和大于0时，必然全加，但可能存在一个周期的左右两端有负值，故这些负值在最左/右周期的最左/最右侧时不加，而之前求的2个循环的最大值此时即为最左/右端的最大值
        return ans%mod if k<=2 else (max(sum(arr), 0) * (k-2) + ans) % mod
```
