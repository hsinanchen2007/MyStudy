### 关键思路  
**正确思路**
访问节点的左子值为key，则修改左子，右子值为key，则修改右子。
否则继续访问此节点的左子，右子。  
**错误思路**  
访问节点值为key，则修改节点。否则继续访问此节点的左子，右子。 
**修改节点的方法**
将节点的左右子树合并组成新二叉搜索树。
### 修改节点的函数
```python
def newnode(i):
    if None in [i.left,i.right]:
        return i.left or i.right
    else:
        ii = i.left
        while ii.right:
            ii = ii.right
        ii.right = i.right                
        return i.left
```
### 自下而上
```python
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        def dn(node):
            if node==None:
                return
            if node.val==key:
                return newnode(node)  ## 实际运行前先复制上面newnode定义                          
            elif node.val>key:
                node.left = dn(node.left)
            elif node.val<key:
                node.right = dn(node.right)
            return node
        return dn(root) 
```
### 自上而下
```python
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:   
        self.root = TreeNode(float('inf'))
        self.root.left = root    
        def dn(node):
            if node==None:
                return
            if node.left and node.left.val==key:
                node.left = newnode(node.left)  ## 实际运行前先复制上面newnode定义
                return
            if node.right and node.right.val==key:
                node.right = newnode(node.right)
                return                
            dn(node.left)
            dn(node.right)
        dn(self.root)
        return self.root.left
```