1. 关于深度，通过定义可知：
- 出现一个'('，那么深度+1；
- 出现一个')'，深度-1。
2. 然后，题目要求A和B的深度最小，什么时候深度最小？就让它们的深度尽可能接近。
3. 如何让深度尽可能接近呢？让它们的深度呈现一种互相追赶趋势。
    具体来说，当遍历到seq中的某一个字符s，
- 如果s是'('，分到A或B中会使得深度+1，所以分给当前深度较小的那个；
- 如果s是')'，分到A或B中会使得深度-1，所以分给当前深度较大的那个；


```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        # 深度互相追赶
        a = b = 0 # A和B的初始深度，都是0
        ans = []
        for s in seq:
            if s == '(':
                if a <= b: # A的深度不大于B，分给A
                    a += 1
                    ans.append(0)
                else: # B的深度小，分给B
                    b += 1
                    ans.append(1) # 分给B
            else:
                if a >= b: # A的深度较大，分给A
                    a -= 1
                    ans.append(0)
                else:
                    b -= 1
                    ans.append(1)
        return ans
```

