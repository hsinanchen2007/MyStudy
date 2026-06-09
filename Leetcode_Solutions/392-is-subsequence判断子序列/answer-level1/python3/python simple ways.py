### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        '''
        i=0
        j=0
        while i<len(s) and j<len(t):
            if s[i]==t[j]:
                i+=1
                j+=1
            else:
                j+=1
        if i==len(s):
            return True
        else:
            return False
        '''

        '''
        left = -1
        for i in range(len(s)):
            idx = t.find(s[i],left+1)
            if idx==-1:
                return False
            else:
                left = idx
        return True
        '''

        '''
        j = 0
        res = 0
        for i in range(len(s)):
            tmp = s[i]
            try:
                res = t.index(tmp,j)
            except ValueError:
                return False
            else:
                j = res+1
        return True
        '''
        '''
        t = iter(t)
        return all(c in t for c in s)
        '''

        queue = collections.deque(s)
        for c in t:
            if not queue: return True
            if c == queue[0]:
                queue.popleft()
        return not queue

```