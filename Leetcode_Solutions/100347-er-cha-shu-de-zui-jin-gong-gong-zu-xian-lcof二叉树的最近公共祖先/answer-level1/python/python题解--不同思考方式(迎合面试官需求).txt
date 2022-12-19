### 解题思路
**我需要强调的是,不是为了刷题而刷题,而是要思考一个题的不同解法以及它的衍生题型,即使有些思路的复杂度很高或者代码不容易coding,我们也需要不断刺激大脑学会不同的解决方式,尤其是参考大神的一些方法会让我们受益匪浅,也欢迎小伙伴们一起讨论,批评指正,共同进步!!!**
***在此感谢各位大神的思路和代码让我受益匪浅!!!散花***
- 这个题目是在二叉搜索树的基础上演变过来了的,可以说是加大了一点难度,因为给我们的树只是普通的二叉树了,没有搜索树的特性,参考剑指offer以及题解,介绍下各种思路.
- 先上图,以下想法均以此图为例: 需要寻找`4`和`6`的最近祖先
![image.png](https://pic.leetcode-cn.com/201d0829f9effb3587b1b06d9c1b6394e34aa9dabcbcdc0b0c872a74047137a2-image.png)

- 下面讨论保存路径形式的思考方式:
1. 第一种:假设给我们的树中的节点包含一个指向父节点的指针
- 如果有了父节点的指针,到达`4`的逆序路径能得出来为`4->2->5->3`,到达`6`的逆序路径为`6->5->3`由于都有父节点指针,所以这个问题就转换成了求两个链表的第一个公共节点问题
2. 第二种:使用数组存储路径
- 给我们的节点没有指向父节点的指针,我们可以使用两个数组保存路径,用先序遍历存储正向路径
- 如节点`4`的正向路径为`3->5->2->4`,节点`6`的正向路径为`3->5->6`,从头找到第一个不相同节点的前一个节点即可,这个例子就是指的节点`5`

### 思路二代码

![image.png](https://pic.leetcode-cn.com/e3008d64266f75e3207a713569d6dc77f1cf717507de8eeb3551af9b383bec10-image.png)
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        stack_1 = []
        stack_2 = []
        def dfs(root, node, stack):
            if not root:
                return False
            stack.append(root)
            if root.val == node.val:
                return True          
            if (dfs(root.left, node, stack) or dfs(root.right, node, stack)):
                return True
            stack.pop()
            
        dfs(root, p, stack_1)
        dfs(root, q, stack_2)
        i = 0
        while i < len(stack_1) and i<len(stack_2) and stack_1[i] == stack_2[i]:
            result = stack_1[i]
            i += 1
        return result

```

### DFS(后续遍历)
![image.png](https://pic.leetcode-cn.com/0c6aeedabcc18e99847d1cb38069f2203a30f66a04aff1e72ff5ceae7f7fb0ad-image.png)

- 这里讨论下通过后续遍历实现
- 参考[https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/shuang-100fei-di-gui-di-gui-shi-xian-by-happy_yuxu/]()
- 若root中只包含p则返回p
- 若root中只包含q则返回q
- 若root中不包含p也不包含q则返回NULL
- 若root中同时包含p和q，则返回root（此时root为最近公共祖先

### 代码
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if not left:
            return right
        if not right:
            return left
        return root




```










