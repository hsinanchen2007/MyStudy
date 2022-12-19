- 做过数组还原平衡二叉搜索树（推荐先做`题号108`），我们知道，在`array`中每次取中点作为根节点，左右分别构建左右子树，递归直至根节点为空。
- 链表的特性导致我们无法像数组那样通过下标访问各个元素。若想按照`108题`的做法，就需要设置两个指针`p1` `p2`，`p1`每走一步`p2`走两步，这样`p2`结束时`p1`就在中点。但这样会导致每次递归都需要重复遍历链表，效率较低。
- 我们考虑是否可以让建立节点的顺序匹配链表元素顺序？这样每次建立节点时，只需要获取链表下一个元素即可。
- 使用递归模拟`中序遍历`过程，建立节点的顺序即与链表元素顺序一一对应，`bottom-up`建立树，最终返回根节点。
- 递归前需要统计链表长度`n`，整体算法复杂度`O(N)`。


```python []
class Solution:
    def __init__(self):
        self.head = None
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        n, self.head = 0, head
        while head:
            head = head.next
            n += 1
        return self.to_bst(0, n - 1)
    def to_bst(self, left, right):
        if left > right: return
        m = (left + right) // 2
        left_child = self.to_bst(left, m - 1)
        father = TreeNode(self.head.val)
        self.head = self.head.next
        father.left = left_child
        father.right = self.to_bst(m + 1, right)
        return father
```
```java []
class Solution {
    private ListNode node;
    public TreeNode sortedListToBST(ListNode head) {
        int n = 0;
        node = head;
        while(head != null){
            head = head.next;
            n++;
        }
        return toBST(0, n-1);
    }
    private TreeNode toBST(int left, int right){
        if(left > right) return null;
        int m = (left + right) / 2;
        TreeNode left_child = toBST(left, m-1);
        TreeNode father = new TreeNode(node.val);
        node = node.next;
        father.left = left_child;
        father.right = toBST(m+1, right);
        return father;
    }
}
```

