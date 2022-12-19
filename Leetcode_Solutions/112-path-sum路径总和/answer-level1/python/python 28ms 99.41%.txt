用BFS,把（node, 剩余的值）储存在栈里，每次pop出来检查剩余的值是否为0，如果不是就把左右子节点及其剩余的值打包进栈里


注意如果到了某一个leave剩余值不为0不要return False，菜鸡如我刚开始就写错了。。（求轻喷）
```
 from collections import deque
  class Solution(object):
     def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
         if not root:
            return False

         queue = deque([(root, sum - root.val)])
        
         while queue:
             node, diff = queue.popleft()
            
             if node:
                 if diff == 0 and not node.left and not node.right:
                     return True

                 if node.left:
                     queue.append([node.left, diff - node.left.val])
                 if node.right:
                     queue.append([node.right, diff - node.right.val])
         return False 
            

```
