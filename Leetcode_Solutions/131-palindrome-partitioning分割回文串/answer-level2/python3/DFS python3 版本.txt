根据大神的题解 [回溯 优化(使用动态规划预处理数组)](https://leetcode-cn.com/problems/palindrome-partitioning/solution/hui-su-you-hua-jia-liao-dong-tai-gui-hua-by-liweiw/)  整理的python版本.

不过内存占用还是有点高. 


```
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        path = []
        cur_len = 0

        def cal(subs):
            pre_len = len(path)
            if len(subs) == 0:
                res.append(path[:])
                return
            for i in range(1, len(subs)+1):
                if self.isPalindrome(subs[:i]):
                    if len(path) > pre_len:
                        del path[pre_len:]
                    path.append(subs[:i])
                    cal(subs[i:])

        cal(s)
        return res


    def isPalindrome(self, subs) -> bool:
        mid = len(subs) // 2
        for i in range(mid):
            if subs[i] != subs[-(i+1)]:
                return False
        return True
```

