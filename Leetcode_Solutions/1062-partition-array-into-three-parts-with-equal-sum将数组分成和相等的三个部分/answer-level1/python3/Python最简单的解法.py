题目意思是把列表拆分成三段（要连续），使得每一段的和s相等，那么可以先把s求出来，从左至右循环累加，直到count==s，然后把count归0开始求第二段的和（通过在if条件中加上pos标志）；第三段的和就不用求了。
```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s  = int(sum(A) / 3)
        pos, count =0, 0
        for a in A:
            count += a
            if count == s and pos == 1:  # 求得第二段的和
                return True
            if count == s:  # 求得第一段的和
                count, pos = 0, 1
        return False
```
