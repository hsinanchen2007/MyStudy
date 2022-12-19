### 解题思路
就这难度还中等？

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        '''1 先计算最大深度，再根据最大深度，一分为二'''
        if not seq:
            return [0]
        depth=0
        answer=[]
        for s in seq:
            if s=="(":
                depth+=1
                answer.append(depth%2)
            else :
                answer.append(depth%2)
                depth-=1
        return answer
        


```