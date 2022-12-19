```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        queue, result, flag = [root, ], [], False
        if not root:
            return result
        
        while queue:
            length, level, flag = len(queue), [], not flag

            for i in range(length):
                node = queue[i]
                '''相比于上一题，增加flag变量，根据flag变量来判断对level内容的改变'''
                if not flag:
                    level.insert(0, node.val)  
                else:
                    level.append(node.val)
                '''==========================='''

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

            queue = queue[length:]
            result.append(level)  
            # 当然也可以考虑在这里，根据flag对level进行reversed操作，而且理论上来说会更省时间
            # 毕竟每次level的insert操作都是O(N)的时间复杂度

        return result
```