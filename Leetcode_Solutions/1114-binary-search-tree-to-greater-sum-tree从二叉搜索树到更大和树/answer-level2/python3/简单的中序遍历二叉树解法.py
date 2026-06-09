简单理解题目的用意，即将二叉树进行排序，排序后从后往前逐个相加
`二叉树:[4,1,6,0,2,5,7,3,8]`
`排序后:[0,1,2,3,4,5,6,7,8]`
`从后往前逐个相加:[36,36,35,33,30,26,21,15,8]`
所以对二叉树进行如下操作：
`1. 中序遍历，节点由小到大进入栈`
`2. 逐个出栈，出栈的同时更新节点的值`
```
class Solution:
    def processNode(self,node,stack):
        if node.left is not None:
            self.processNode(node.left,stack)
        stack.append(node)
        if node.right is not None:
            self.processNode(node.right,stack)
        return
    def bstToGst(self, root):
        if root==None:
            return None
        stack=[]
        self.processNode(root,stack)
        curSum=0
        while len(stack)!=0:
            elem=stack.pop()
            elem.val+=curSum
            curSum=elem.val
        return root
```
![批注 2019-12-02 235032.png](https://pic.leetcode-cn.com/6c1ab4c842e6b297830107683dd7e75a9995dfa9c855936c647f80b13d464f9d-%E6%89%B9%E6%B3%A8%202019-12-02%20235032.png)
