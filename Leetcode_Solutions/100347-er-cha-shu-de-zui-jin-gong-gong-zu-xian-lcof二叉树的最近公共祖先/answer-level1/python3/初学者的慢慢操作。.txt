### 解题思路

先想特殊情况(空)，简单或者说极限情况(直接根就是p或q)，作为临界条件。
if root is None :
            return None
elif root in [p,q]:
            return root
基本上上面就是没找到和找到一个的临界条件。
找到大概会写成:
if CommonAncestor(root.left,p) return CommonAncestor(root.left,p)

写个算法判断当前节点root是否是p的根节点，返回TRUE与NONE
def isAncestor(self, root, p):
        if root is None:
           return False
        elif root==p:
           return True
        elif  :
           return  CommonAncestor(root.left,p) or CommonAncestor(root.right,p)
考虑非要用节点代替True条件与返回值，肯定就不能or了，而得用条件与None做控制流，简单来说总得写成：
def isAncestor(self, root, p):
        if root is None:
             return None
        elif root == p:
             return root
        elif CommonAncestor(root.left,p): #左儿子找到，否则不赋值
        return CommonAncestor(root.left,p)
        elif CommonAncestor(root.right,p): #右儿子找到则赋值，否则不赋值
        return  CommonAncestor(root.right,p)
        else:
        return None
上面这个可以这样写是因为左右逻辑情况只有两种额，因为我们只找一个，但找两个时高于两种状态所以只能用设left，right两个变量。
left=self.lowestCommonAncestor(root.left,p,q)
right=self.lowestCommonAncestor(root.right,p,q)

现在考虑除了临界情况以外 ，root与pq的情况无非root在p，q之间，在p，q右侧，在p，q左侧。而在p，q之间其实有且只有最近公共祖先的情况。而在p，q右侧则应该返回根的右儿子，左侧即根的左儿子。


而控制流就用上面的left与right即可完成。



             
        


                 



### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if root is None :
            return None
        elif root in [p,q]:
            return root
        else : 
            left=self.lowestCommonAncestor(root.left,p,q)
            right=self.lowestCommonAncestor(root.right,p,q)
            if not left and not right:
                return None
            elif not left and right:
                return right
            elif left and not right:
                return left
            else :
                return root  
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
```