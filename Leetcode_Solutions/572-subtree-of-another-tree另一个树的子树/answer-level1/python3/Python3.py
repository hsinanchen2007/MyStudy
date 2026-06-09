### 解题思路
easy做了一小时...好在思考尝试结果和官方方法2一样,恢复了一点信心

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:

        #1. 直觉:  前序遍历, 因为先要root是否和t.val相同.    
        # def traverse(root,):
        #     if not root: return False
        #     if root.val ==
        #     traverse(root.left)
        #     traverse(root.right)
        #
        #2. 稍微改一下:
        #直接用isSubtree, 两给变量,待遍历和目标,这样思路更清晰:
        #base case:
        # if not t and not s: return True
        # if not s or not t: return False
        # res = None

        # if s.val == t.val:
        #     #return (self.isSubtree(s.left,t.left) and self.isSubtree(s.right, t.right)) or self.isSubtree(s.left,t) or self.isSubtree(s.right,t)
        #     #这里开始没有写后半段or self.isSubtree(s.left,t) or self.isSubtree(s.right,t),无法兼容又重复元素的树.
        #     #不过这样简单补了下 case也faile了, 索性重新梳理下逻辑:
        #     if s.left == t.left and self.isSubtree(s.left,t.left) and self.isSubtree(s.right, t.right): #不对, 因为子树包含t.left 不代表root的儿子是t.left.
        #         res = True
        #     else:
        #         res = self.isSubtree(s.left,t) or self.isSubtree(s.right, t)
        # else:
        #     #return False?? 这样不行, 因为函数的定义是整个树有没有子树,root不一样,子树还有可能
        #     #??res = self.isSubtree(s.left,t) or self.isSubtree(s.right, t) 这样也不全对,对于t是对的,对于t的子树,不对. 
        # return res    

        # # else:
        # #     return self.isSubtree(s.left,t) or self.isSubtree(s.right,t)
        #3.用原本的定义 好像不太好做,还是重新定义一个函数: 
        def traverse(root,t):#以root为跟节点的树是否和t完全相等
            if not t and not root: return True
            elif not root or not t: return False
            #原来的判断空用不上了, 因为主函数已经把s/t为空判断过了??
            #if not root: return False
            #if root.val != t.val: return False 冗余:下面第一个式子运算完就直接跳出来了.
            return root.val == t.val and traverse(root.left, t.left) and traverse(root.right, t.right)
                
            # elif root.val == t.val and (not traverse(root.left, t.left) or not traverse(root.right,t.right)) :
            #     return traverse(root.left,t) or traverse(root.right,t)
            # elif root.val != t.val:
            #     return traverse(root.left,t) or traverse(root.right,t)
            #网友答案:
#              private boolean equals(TreeNode t1, TreeNode t2) {
#         if (t1 == null && t2 == null) return true;
#         else if (t1 == null || t2 == null) return false;

#         return t1.val == t2.val && equals(t1.left, t2.left) && equals(t1.right, t2.right);
#     }
# }


        if not t and not s: return True
        if not t or not s: return False
        
        #bfs?
        queue = [s]
        while queue: #循环
            s = queue.pop(0)
            if not s: continue
            res = traverse(s,t)
            if res:
                return True
            else:
                queue.append(s.left)
                queue.append(s.right)
        return False





```