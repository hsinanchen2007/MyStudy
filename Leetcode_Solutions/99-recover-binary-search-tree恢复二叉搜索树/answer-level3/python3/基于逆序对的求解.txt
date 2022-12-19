先上图，这个方法看起来效果还可以
![leetcod_99.png](https://pic.leetcode-cn.com/129cf5589c4e29acca48ecc7dee675553606cc21d557ab34d06b19c3c32a08f2-leetcod_99.png)

题目说二叉搜索树中的只有两个节点被错误地交换。
在不使用额外空间的情况下，解题的关键在于找出哪两个节点之间进行了交换。
二叉搜索树的节点都是有序的，两个节点交换也就是所有节点的中序遍历序列中只有一对逆序对。
![Inkedleetcode_99_1_LI.jpg](https://pic.leetcode-cn.com/536bdeefb924ad47d29c617dbc06af8e8febee28ee6fdbaf1b417c3b52e92a5b-Inkedleetcode_99_1_LI.jpg)
这里（1，1），（1，3）没有逆序，之后（3，2）逆序，（2，4）没有逆序
ans = [(节点3，节点2)]

代码如下
```
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def myfun(front,ans,root):          #函数内函数，用于找出逆序对，front[]用来传递参数，让我在递归底层修改参数后上层还能用
            if root.left != None:           #ans里面是逆序对的元组，初始为空
                myfun(front,ans,root.left)  #典型的递归中序遍历
            if front[0].val > root.val:     #有逆序对，保存起来，否则什么也不做
                ans.append((front[0],root))
            front[0] = root                 #把front里的元素改为当前节点，供后续比较使用
            if root.right != None:
                myfun(front,ans,root.right)
                
        p = root
        while p.left != None:
            p = p.left
        front = [p]                         #此时front中只有一个元素，初始化为左子树最左边元素，即最小的元素。
        ans = []
        myfun(front,ans,root)               #myfun运行完成，ans里面可能有两个元组，交换的节点不相邻，也可能只有一个元组
        ans[0][0].val,ans[-1][-1].val = ans[-1][-1].val, ans[0][0].val
```

通过一个函数内函数找出有逆序的元素对，主要交换逆序的两元素即可