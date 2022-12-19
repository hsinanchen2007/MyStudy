
### 解题思路：

注意是只能和自己的祖宗节点比较，拥有共同父节点的左右子树互相之间不能比较  
方法：  
- 一口气遍历到叶子节点，遍历的时候动态保存当前路径的最大节点值和最小节点值  
- 每当遍历一次叶子节点，将保存好的最大值与最小值之间的差与全局变量 `maxvalue` 比较，并且取较大值  

### 代码：
```Python [-Python]]
class Solution:
    self.maxvalue=0
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.dfs(root,0,100001)
        return self.maxvalue
    
    def dfs(self,node,maxv,minv):
        if not node:
            self.maxvalue = max(maxv-minv, self.maxvalue)
        else:
            maxv, minv = max(maxv,node.val), min(minv,node.val)
            self.dfs(node.left,maxv,minv)
            self.dfs(node.right,maxv,minv)  
```