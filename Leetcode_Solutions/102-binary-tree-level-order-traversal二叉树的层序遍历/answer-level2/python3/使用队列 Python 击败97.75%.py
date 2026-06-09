1. 运用数据结构中队列的知识，开始时队列helper中只有根节点，访问helper中的每一个节点，依次将结点的值保存在列表tmp1中， 并将节点的左右孩子（如果有的话）加入临时列表tmp2
2. 用临时列表tmp2替换helper，继续遍历，直到helper为空
  
     

```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        helper = [root]
        res = []
        while helper:
            tmp1 = []
            tmp2 = []
            for node in helper:
                tmp1.append(node.val)
                if node.left:
                    tmp2.append(node.left)
                if node.right:
                    tmp2.append(node.right)
            res.append(tmp1)
            helper = tmp2
        return res
```

