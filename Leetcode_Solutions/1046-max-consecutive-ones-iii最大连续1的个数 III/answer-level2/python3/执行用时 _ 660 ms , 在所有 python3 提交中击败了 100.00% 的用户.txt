```
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        # 用来记录子串的开始下标
        i = 0
        n = len(A)
        for j in range(0, n):
            # 如果遇到0的时候，k减一，直到k=0的时候，此时的字串为到j的位置时，全为一的最长子串。
            if A[j] == 0:
                k -= 1
            # 如果k为零时，此时的最长子串已经在遍历过j之前的元素中最长，此时j-1+1为最长子串，这时i可以进行随着k进行移动，如果遇到i位置的数字为0时，表示可以取消一个反转的0，从而以便可以进行更长子串的搜索
            if k < 0:
                if A[i] == 0:
                    k += 1
                i += 1
        return j-i+1
```
此解法为b站大佬的解法，为搬运而来，膜拜大佬的链接https://www.bilibili.com/video/av45741013?t=40
