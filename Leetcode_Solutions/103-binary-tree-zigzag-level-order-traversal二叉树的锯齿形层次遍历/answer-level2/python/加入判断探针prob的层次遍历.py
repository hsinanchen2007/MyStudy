### 解题思路
相交于102题：
（1）首先遍历的方式没有改变，每一层都是按照从左到右来进行遍历。
（2）只是输出的顺序变化了，顺序和层数有关，所以我们加入一个判断 prob ，当是奇数层的时候是1，反之-1。
（3）定义一个函数f（tmp，prob），其中tmp为每一层中的节点，prob为+-1，每向下传播一次prob取-prob即可。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        def  f(tmp,prob):
            if not tmp:
                return
            a=[]
            tmp1 = []
            
            for node in tmp:
                a.append(node.val)
                if node.left:
                    tmp1.append(node.left)
                if node.right:
                    tmp1.append(node.right)
            if prob ==1:
                res.append(a)
            if prob ==-1:
                a.reverse()
                res.append(a)
            f(tmp1,-prob)
        res =[]
        if not root:
            return []
        f([root],1)
        return res
                





```