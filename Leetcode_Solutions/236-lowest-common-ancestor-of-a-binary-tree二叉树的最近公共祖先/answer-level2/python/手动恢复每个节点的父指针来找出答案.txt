```Python
# -*- coding:utf-8 -*-

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

"""
思路：寻找共同父节点，一般都是都是通过父指针来实现。但是本题没有父指针，所以先把父指针撸出来
第一步：由于无法改变之前的TreeNode数据结构，所以这里可以通过一个字典来维护。遍历一遍树几个全部搞定
第二步：在第一步字典的基础上找出p、q的父节点链条，自下而上找
第三步：第二部找出的两个列表倒序找最后一个共同节点就是答案
[1,4,5]
[2,4,5]
最后一个公共节点4
"""

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        dicPar = {}
        dicPar[root.val] = None
        self.getParnode(root, dicPar)
        p_par_list = self.getParlist(p,dicPar)
        q_par_list = self.getParlist(q,dicPar)
        return self.getMinCommon(p_par_list,q_par_list)

    def getParlist(self,root,dicPar):
        res = [root]
        curr = root
        while True:
            par = dicPar[curr.val]
            if par is None:
                break
            res.append(par)
            curr = par
        return res

    def getParnode(self, root, dicPar):
        if root is None:
            return
        l = root.left
        r = root.right
        if l is not None:
            dicPar[l.val] = root
        if r is not None:
            dicPar[r.val] = root
        self.getParnode(l, dicPar)
        self.getParnode(r, dicPar)

    def getMinCommon(self,lst1,lst2):
        lst1.reverse()
        lst2.reverse()
        min_len = min(len(lst1),len(lst2))
        for i in range(min_len):
            if lst1[i] != lst2[i]:
                return lst1[i-1]
        return lst1[min_len-1]
if __name__ == "__main__":
    # t1 = TreeNode(3)
    #     # p = TreeNode(5)
    #     # t1.left = p
    #     # q = TreeNode(1)
    #     # t1.right = q
    #     # t1.left.left = TreeNode(6)
    #     # t1.left.right = TreeNode(2)
    #     # t1.left.right.left = TreeNode(7)
    #     # t1.left.right.right = TreeNode(4)
    #     # t1.right.left = TreeNode(0)
    #     # t1.right.right = TreeNode(8)

    p = TreeNode(1)
    t1 = p
    q = TreeNode(2)
    t1.left = q


    new = Solution().lowestCommonAncestor(t1,q,p)
    print new.val
```
