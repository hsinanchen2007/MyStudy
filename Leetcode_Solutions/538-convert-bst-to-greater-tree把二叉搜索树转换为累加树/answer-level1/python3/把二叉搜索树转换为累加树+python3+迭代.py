### 迭代
使用迭代法，对原始二叉树进行中序遍历，将栈来做临时存储，再对里面的元素一一处理。代码如下：
```
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        target = []
        stack = []
        head = root
        while root:
            stack.append(root)
            root = root.left
            if not root:
                root = stack.pop()
                target.append(root)
                while not root.right and stack:
                    root = stack.pop()
                    target.append(root)
                root = root.right
                
        n = len(target)
        for i in range(n-2,-1,-1):
            target[i].val=target[i+1].val+target[i].val
        return head
            
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)
