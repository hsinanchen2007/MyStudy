### 递归
递归的思路很简单，利用二叉搜索树的特点，代码如下：
```
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root: #如果为空，直接pass
            pass
        else:
            if root.val == val: #如果等于目标值，返回该结点
                return root
            elif root.val >val: #大于目标值，搜索左子树
                return self.searchBST(root.left,val)
            else:    #小于目标值，搜索右子树
                return self.searchBST(root.right,val)
        
        return None #没找到，返回None
```
#### 复杂度分析
__时间复杂度：__ 每个结点至多访问一次，平均复杂度O(n);

__空间复杂度：__ 完全不平衡树O(n), 平衡树O(log(n))

### 迭代法
思路就是用一个栈做存储，在一个个弹出来判断，是目标值则返回，不是压入左右子树，继续循环，直至结束。代码如下：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        stack = [root]
        while stack:
            tmp = stack.pop()
            if tmp == None:
                continue
            if tmp.val == val:
                return tmp
            else:
                stack.append(tmp.left)
                stack.append(tmp.right)
        return None
```

#### 复杂度分析

__时间复杂度:__ O（n）

__空间复杂度:__ O（n）

### 直接遍历
采用的是[@skx](/u/skx)的解法，我把判断顺序改了一下，好像会稍微快一点。因为这题是二叉搜索树，因此可以直接遍历，用root去指向当前结点，代码如下：
```
class Solution:
    def searchBST(self, root, val):
        while root:
            if root.val== val:
                return root
            elif root.val > val:
                root = root.left
            else:
                root = root.right
        return None
```

#### 复杂度分析
__时间复杂度:__ O(n)

__空间复杂度:__ O(l)

这是目前时空复杂度表现最好的一种解法。