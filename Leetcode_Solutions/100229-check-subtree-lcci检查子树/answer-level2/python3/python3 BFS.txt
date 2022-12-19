### 解题思路
BFS + 简单递归，内存消耗还行
![image.png](https://pic.leetcode-cn.com/4f44c6df2b69e1615792f14c9069b5e1a4bd9f7ead39890d3ae4285d275e394e-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def checkSubTree(self, t1: TreeNode, t2: TreeNode) -> bool:
        def compare(T1, T2):
            if T1 and T2:
                if T1.val == T2.val:
                    return compare(T1.left, T2.left) and compare(T1.right, T2.right)
            if (not T1) and (not T2):
                return True
        
        if t1 ==None:
            return False
        if t2 == None:
            return True

        stack = [t1]
        
        # while len(stack) > 0:
        #     tmp = stack.pop()
        #     if tmp:
        #         if tmp.val != t2.val:
        #             if tmp.left != None:
        #                 stack.append(t1.left)
        #             if tmp.right != None:
        #                 stack.append(t1.right)
        #         else:
        #             judge = compare(tmp, t2)
        #             if judge:
        #                 return True
        #             else:
        #                 continue
        # return False

        while len(stack) > 0:
            tmp = stack.pop()
            if tmp:
                judge = compare(tmp, t2)
                if judge:
                    return True
                else:
                    stack.append(tmp.left)
                    stack.append(tmp.right)
        return False
            
```