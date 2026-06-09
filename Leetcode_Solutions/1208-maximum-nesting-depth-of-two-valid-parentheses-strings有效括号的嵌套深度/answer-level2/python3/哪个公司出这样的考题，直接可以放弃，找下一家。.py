### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = []
        """
        for i, s in enumerate(seq):
            if s == '(':
                ans.append(i%2)
            else: 
                ans.append((i+1)%2)
        return ans
        """
        q = collections.deque()
        for i in seq:
            if i == '(':
                q.appendleft('(')
                ans.append(len(q)%2)
            else:
                q.popleft()
                ans.append((len(q)+1)%2)
        return ans

```