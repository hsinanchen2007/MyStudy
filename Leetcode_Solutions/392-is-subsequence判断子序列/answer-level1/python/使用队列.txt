使用队列保存当前未找到的字符，遍历序列t，直到队列为空或t遍历完
```
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        l = len(t)
        curr = 0
        queue = list(s)
        while queue and curr < l:
            if t[curr] == queue[0]:
                queue.pop(0)
            curr += 1
        return len(queue) == 0

```
