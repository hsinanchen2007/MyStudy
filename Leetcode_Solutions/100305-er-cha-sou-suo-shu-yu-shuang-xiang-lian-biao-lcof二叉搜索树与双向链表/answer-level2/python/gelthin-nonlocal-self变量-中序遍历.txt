### 解题思路
此题曾被面试拿来考过，来自知乎 [bst转 linked list](https://www.zhihu.com/question/315431369/answer/657307652)
同 [主站 426 题](https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)，但主站习题需要购买才能打开。


参考了优秀解答 [面试题36. 二叉搜索树与双向链表（中序遍历，清晰图解）](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/mian-shi-ti-36-er-cha-sou-suo-shu-yu-shuang-xian-5/)。

+ 优秀解答中讨论了 self 变量是类变量，可以当做全局变量使用，随时修改。这一用法好像在其他题解中也见到过。待后面总结。进一步的理解作者给出了链接 [大家是如何理解Python中的self？](https://www.zhihu.com/question/39264541)

+ 我这里把它改为了 nonlocal 关键字声明的变量。关于 nonlocal 我其他地方也有讨论。例如 [gelthin-复习python global-nonlocal](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/gelthin-fu-xi-python-global-nonlocal-by-gelthin/) 还有其他一些题解中也提到了此。

+ 当然这一个变量 pre 也可以当做参数传递，但是内部修改了，则需要进行更新传出来。


### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        # https://www.zhihu.com/question/315431369/answer/657307652
        def inorder(cur):  # 树算法一定要依照树的框架来写
            nonlocal pre  # 用这个取代 self.pre
            if not cur:
                return
            inorder(cur.left)
            
            pre.right, cur.left = cur, pre
            pre = cur  # 修改了这一个值
            
            inorder(cur.right)

        if not root:
            return root

        prenode = Node(-1)
        pre = prenode
        inorder(root)
        first_node = prenode.right
        first_node.left = pre # pre 指向了最后一个节点 5
        pre.right = first_node
        return prenode.right

### 使用 self 变量，来自他人的题解。
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def dfs(cur):
            if not cur: 
                return
            dfs(cur.left) # 递归左子树
            self.pre.right, cur.left = cur, self.pre # 修改引用
            self.pre = cur # 保存 cur
            dfs(cur.right) # 递归右子树
        
        if not root: 
            return
        head = ListNode(0) # 伪头节点
        self.pre = head   # 这里特殊在于 self.pre 可当做全局变量，随时修改更新，先前在哪里也看到这一用法
        dfs(root)         # 不然要使用 nonlocal 声明
        head = head.right
        head.left, self.pre.right = self.pre, head
        return head
```