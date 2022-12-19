### 递归
这是一种自上而下的实现
```python
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        self.rst = []
        def po(node):
            if node:
                self.rst.append(node.val)
                [po(i) for i in node.children]                    
        po(root)
        return self.rst
```
### 迭代
这是一种参考[这里](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/)的实现
```python
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        stack,rst = root and [root], []
        while stack:
            i = stack.pop()
            if isinstance(i,Node):
                stack.extend([x for x in i.children][::-1]+[i.val])
            elif isinstance(i,int):
                rst.append(i)
        return rst
```