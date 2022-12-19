直接按照题目描述构建代码，中间判断部分参考了题目“删除排序数组中重复项”的部分思想。

```
class Solution(object):
    def countAndSay(self, n):
        if n == 1: return "1"
        ans = "1"
        for loop in range(2, n + 1):
            tmp = ""
            idx = 0
            for j in range(len(ans)):
                if ans[j] != ans[idx]:
                    tmp = tmp + str(j - idx) + ans[idx]
                    idx = j
            if ans[j] == ans[idx]:
                tmp = tmp + str(j-idx+1) + ans[idx]
            ans = tmp
        return ans
```
