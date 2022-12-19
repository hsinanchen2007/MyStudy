### 解题思路
python宽度优先搜索法。优化思路：找到第一个叶子节点即退出搜索。
### 代码

```python

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:return 0
        cur=[root]
        minh=0                                      #minh记录高度
        while cur!=[]:                              #这个循环每进行一次，即是扫完一层
            nextlayer=[]
            minh+=1                                 
            for p in cur:
                if p.left==None and p.right==None:  #左右子树为空即该节点为叶子节点
                    return minh
                else:
                    if p.left!=None:
                        nextlayer.append(p.left)
                    if p.right!=None:
                        nextlayer.append(p.right)
            cur=nextlayer
        
```