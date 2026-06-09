### 解题思路
##递归思路
题目要求我们用递归和迭代方法来反转链表，明显递归的思路会比迭代难一些，但递归写出来的思路会比迭代清晰一点，这里是我的递归思路：等到链表的节点为最后一个节点时，我们将其视为头结点并且返回，因为在生成链表的过程需要不断递推下去，所以我们需要一个tmp来承担这个功能，这里我们用head2=head1 中的head2来承担这个功能，这样在递归完最后一个节点后，明显会返回到倒数第二个节点，这里我们用head2来承接这个第二节点，以此类推，直到返回到第一个节点后，我们递归完成。head1就是我们要的值
##迭代思路
迭代思路很简单，把链表的值储存到list中，在反向输出构建就可以。

### 递归代码

```python
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #递归
        if not head:
            return None
        def digui(node):
            if node.next==None:
                head1=ListNode(node.val)
                head2=head1
                return head2,head1
            head2,head1=digui(node.next)
            node_new=ListNode(node.val)
            head2.next=node_new
            return head2.next,head1
        a,res=digui(head)
        return res
```
### 迭代代码

```python
#迭代
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #迭代
        tmp=[]
        if not head:
            return None
        while head!=None:
            tmp.append(head.val)
            head=head.next
        for i in range(len(tmp)):
            if i==0:
                head1=ListNode(tmp[-1])
                head2=head1
            else:
                node=ListNode(tmp[-1-i])
                head2.next=node
                head2=head2.next
        return head1
```