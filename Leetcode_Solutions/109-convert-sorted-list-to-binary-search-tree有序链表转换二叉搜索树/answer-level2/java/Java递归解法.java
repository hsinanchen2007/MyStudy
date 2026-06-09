
题目需要我们构造一棵高度平衡的二叉搜索树，二叉搜索树即对于任一节点，其左子树的值都比它小，右子树的值都比它大。
### 解题思路
刚好链表中的元素是升序的。因此我们可以取中间元素作为节点，再取其左边区域的中间元素作为左子树，右边区域的中间节点作为右子树。如此递归下去，便能将高度平衡的二叉搜索树构造出来。


#### 重点
- 寻找链表的中间节点。（利用快慢双指针法）
- 将中间节点的左边断开，形成边界。

### 代码

```java
class Solution {
        
    public TreeNode sortedListToBST(ListNode head) {
        if(head==null)return  null;
        //当链表只剩一个元素时，直接构造节点。否则会造成栈溢出。
        if(head.next==null)return new TreeNode(head.val);
        ListNode slow=head,fast=head,prev=null;
        //利用快慢双指针寻找中间节点
        while(fast!=null&&fast.next!=null){
            prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        //将中间节点断开
        if(prev!=null)prev.next=null;
        TreeNode root = new TreeNode(slow.val);
        //构造左子树
        root.left=sortedListToBST(head);
        //构造右子树，从中间节点的下个节点开始
        root.right=sortedListToBST(slow.next);
        return root;
    }
    
    
}
```