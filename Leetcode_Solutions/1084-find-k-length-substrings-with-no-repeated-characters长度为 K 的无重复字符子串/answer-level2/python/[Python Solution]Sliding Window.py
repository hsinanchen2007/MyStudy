执行用时 :24 ms, 在所有 Python 提交中击败了100.00%的用户
内存消耗 :13 MB, 在所有 Python 提交中击败了100.00%的用户
```
def numKLenSubstrNoRepeats(self, S, K):
    l, res = 0, 0
    dict = {}
    for r in range(len(S)):
        if S[r] not in dict:
            dict[S[r]] = 1
        else:
            while S[l] != S[r]:
                del dict[S[l]]  # 由于S[l:r]必然是不含重复字符的子串，直接删除即可
                l += 1
            l += 1  # 跳过重复元素
        if r - l + 1 == K:
            res += 1
            del dict[S[l]]
            l += 1
    return (res)
```
解题思路：
对于滑窗问题，最重要的在于如何判断左指针的滑动。
假设`S = "abeffca", K = 3`。
当`r = 2, l = 0`的时候，左指针向右滑动一位。
当`r = 3, l = 1`的时候，左指针向右滑动一位。
当`r = 4, l = 2`的时候，由于"f"存在于"ef",左指针开始向右移动，直到"f"不出现在窗口中。

