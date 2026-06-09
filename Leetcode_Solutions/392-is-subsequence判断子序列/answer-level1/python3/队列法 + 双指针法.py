### 解题思路
思路见代码

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        """
        双指针法，用两个指针分别指向s和t
        """
        p_s, p_t, res = 0, 0, 0
        while p_s < len(s) and p_t < len(t):
            if s[p_s] == t[p_t]:
                p_s += 1
                p_t += 1
                res += 1 # res 是已经匹配上的字符数
            else:
                p_t += 1
        return res == len(s) # 如果相等，说明是子序列，否则不是
            
    def isSubsequence_queue(self, s: str, t: str) -> bool:
        """
        利用队列，把s串放入到一个队列中，然后逐一匹配t中的元素，如果匹配到，则逐一弹出
        """
        s = deque(s)
        for _t in t:
            if not s: # 在循环过程中，如果队列为空，说明全部都匹配到了，返回True
                return True
            if _t == s[0]:
                s.popleft() # 从队列头部弹出匹配到的元素
        return not s # 如果队列全部为空，则说明都匹配到了

```