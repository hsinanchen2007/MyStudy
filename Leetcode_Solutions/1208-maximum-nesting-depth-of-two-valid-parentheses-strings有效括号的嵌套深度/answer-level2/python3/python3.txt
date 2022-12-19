### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        # 先求出最大嵌套深度, 想使得max(depthA, depthb)最小, 即两者平分深度
        # 理解为seq为一个二叉树, 现将其转为平衡二叉树
        
        if not seq:
            return []
        
        # 使用栈求最大嵌套深度
        depth, stack = 0, []
        for i, x in enumerate(seq):
            depth = max(depth, len(stack))
            if x == '(':
                stack.append(x)
            elif x == ')':
                stack.pop()
        # 平分深度
        depth = max(depth // 2, 1)
        k, tmp = depth, []
        for i, x in enumerate(seq):
            if x == '(' and k > 0:
                tmp.append(i)
                k -= 1
            elif x == ')' and k < depth:
                tmp.append(i)
                k += 1
                
        res = [1] * len(seq)
        for i in tmp:
            res[i] = 0
        return res
```