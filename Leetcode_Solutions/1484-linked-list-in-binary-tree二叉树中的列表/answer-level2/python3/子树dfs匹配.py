# 思路
参考了这位大佬的[解题思路](https://leetcode-cn.com/problems/linked-list-in-binary-tree/solution/zhe-ti-jiu-shi-subtreeyi-mao-yi-yang-by-jerry_nju/)
先假设head是以当前树上节点某一个节点开头的，我们再去dfs寻找这树上是否存在这样一条匹配路径（子树）。

# 代码
解题步骤思路在代码中。

```python
class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        #匹配一个空的路径，一定是True
        if head == None : return True;
        #既然路径不是空了，那么一颗空的树来匹配一定是False
        if root == None : return False;
        '''
        注意 后面两个左右子树的递归并不是match
        要递归isSubPath才能递归整颗树
        '''
        return (self.match(head,root) or self.isSubPath(head,root.left) or self.isSubPath(head,root.right));



    def match(self, head: ListNode, root: TreeNode) -> bool:
        #如果链表已经为空了，那么，则已经匹配完成 True
        if head == None : return True;
        #如果树已经走完了，那么剩下的链表不可能匹配 False
        if root == None : return False;
        #链表匹配中断了，则以这个“head”开头的子树走不通
        if root.val != head.val : return False;


        #dfs,只要有一边能通，就OK
        return (self.match(head.next,root.left) or self.match(head.next,root.right));
```
