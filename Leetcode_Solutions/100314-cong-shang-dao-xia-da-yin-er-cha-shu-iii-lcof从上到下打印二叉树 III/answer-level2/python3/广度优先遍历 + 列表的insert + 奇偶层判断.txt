（1）使用广度优先遍历，但是题目要求每一层的输出顺序和其上一层或下一层的输出顺序是相反的。因此在广度优先遍历中将结点放进队列中的时候，我们同时保存该结点所在的层数，即放进队列中的元素是[node,d]。

（2）其中node表示树的节点，d表示该结点是第几层的节点，默认根节点的层数为0，越往下层数越高。

（3）当层数是偶数层时，我们直接使用append将节点的数据存进列表中。当层数是奇数时，我们使用insert将节点的数据存进列表中，这样就实现了将数据逆序存放。

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
            
        queue = collections.deque([[root,0]])  # 创建队列，保存节点值和节点所在层数
        nums = []  # 用于保存整个遍历的值
        
        while queue:
            num = []  # 用于保存每层的遍历结果
            
            for _ in range(len(queue)):  # 对每一层进行遍历
                node,d = queue.popleft()
                
                if d%2 == 0:  # 如果当前层数为偶数层，则顺序存放
                    num.append(node.val)
                else:    # 如果当前层数为奇数层，则逆序存放
                    num.insert(0,node.val)
                    
                if node.left: 
                    queue.append([node.left,d+1])
                if node.right:
                    queue.append([node.right,d+1])
            nums.append(num[:])
        return nums
```
该方法中的insert()的时间复杂度为O(n)，但是整体的时间复杂度应该也还是O(n)。空间复杂度为O(n)。