### 解题思路
1. **编写了90分钟代码，直至放弃。。。**
2. [将二叉搜索树变平衡 -- Need](https://leetcode-cn.com/problems/balance-a-binary-search-tree/solution/jiang-er-cha-sou-suo-shu-bian-ping-heng-need-by-a-/)
    -  1）原来的树，通过中序遍历得到排序列表；  
    -  2） 二分排序列表重新构建二叉树
    - 此题目也有人 通过AVL 选择做的，个人放弃了

3. [二叉搜索树（理解定义） + 二叉树遍历](https://leetcode-cn.com/problems/trim-a-binary-search-tree/solution/er-cha-sou-suo-shu-li-jie-ding-yi-er-cha-shu-bian-/)
    - 根据定义可知，根节点是中间值，左右子树也满足BST
    - 根据定义可知，**二叉排序树的中序遍历结果，就是从小到大排序的**

3. 最大最小堆：（其堆顶是最值）
    - 最大堆：根结点的键值是所有堆结点键值中最大者，且每个结点的值都比其孩子的值大。
    - 最小堆：根结点的键值是所有堆结点键值中最小者，且每个结点的值都比其孩子的值小
    - **若是二叉树构建堆，其仅仅要求根节点满足要求即可；对左右子树不要求**

4.  根据定义可知，**二叉排序树的中序遍历结果，就是从小到大排序的**
    - 那么此题似乎就可以解决了
    - 看着自己最开始写的代码（错误的），自己就完全根据定义在写代码：**可左子树里面含有右子树的**

5. **递归问题：**
    - **强烈建议 把返回值 作为 全局变量使用**。    
   
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True 
        
        lf = self.pastorder(root.left, root.val, True)
        if lf == False:
            return False 
        rf = self.pastorder(root.right, root.val, False)

        return rf 

    def pastorder(self, root, fu, lorr):
        if root is None:
            return True 
        if lorr and root.val >= fu:
            return False 
        elif lorr == False and root.val <= fu:
            return False 
        lf = self.pastorder(root.left, root.val, True)
        if lf == False:
            return False 
        rf = self.pastorder(root.right, root.val, False)
        
        return rf 
## [10,5,15,null,null,6,20]  false 
## [1,1]  false 
## 错在根上了
'''     
'''
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return None 
        min_, max_ = root.val, root.val 
        lf, max_ = self.pastorder(root.left, max_)
        if lf == False:
            return False 
        rf, min_ = self.pastorder(root.right, min_)
        if rf == False:
            return False 
        if max_ < root.val and min_ > root.val:
            return True 

    def pastorder(self, root, )
''' 
'''
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return None 
        return self.validate(root, float("-inf"), float("inf"))
    
    def validate(self, root, max_, min_):
        if root is None:
            return True 
        
        if root.val <= max_ or root.val >= min_:
            return False 
        
        else:
            return self.validate(root.left, root.val, min_) and self.validate(root.right, max_, root.val)
'''

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        nodes =[]
        def search(root):
            if root:
                search(root.left)
                nodes.append(root.val)
                search(root.right)
        search(root)
        return nodes == sorted(set(nodes))



解法二： 
class Solution:
    def __init__(self):
        self.f = True 
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True 
        
        res, p = self.ValidBST(root, None)
        return res 

    def ValidBST(self, root, pre=None):
        if root is None:
            return True, pre 
        lf, pre = self.ValidBST(root.left, pre)
        if lf == False:
            return False, pre  
        if pre != None and pre >= root.val:
            return False, pre 
        
        pre = root.val 

        return self.ValidBST(root.right, pre)

解法三：强烈建议用此法代替方法二：
class Solution:
    def __init__(self):
        self.f = True
        self.pre = None 

    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True 
        
        self.ValidBST(root)
        return self.f  

    def ValidBST(self, root):
        if root is None or self.f == False: ## self.f == False 相当于剪枝 
            return
        self.ValidBST(root.left)
        if self.pre != None and self.pre >= root.val:
            self.f = False 
            return 
        
        self.pre = root.val 

        return self.ValidBST(root.right)










```