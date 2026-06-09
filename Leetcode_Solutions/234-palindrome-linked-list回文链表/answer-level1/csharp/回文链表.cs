**思路：** 快慢指针的方式，先找到中心节点（过程中反转慢指针前的节点），然后从中间分开成两个链表，然后开始逐个比对看是否相等。

```
public bool IsPalindrome(ListNode head)
        {
            if (head == null || head.next == null)
            {
                return true;
            }

            var slowNode = head;
            var fastNode = head;
            //记录反转后的链表（此处可回忆下反转列表的过程）
            ListNode guardNode = null;
            //step1: 找到中心节点并反转慢指针前的节点（多画图加深理解）
            while (fastNode != null && fastNode.next != null)
            {
                fastNode = fastNode.next.next;
                var tempNode = guardNode;
                guardNode = slowNode;
                slowNode = slowNode.next;
                guardNode.next = tempNode;
            }

            //step2：完成反转后分别设置左右链表的对比起点
            //可以不用增加两个新的变量直接用guardNode和slowNode
            //但是代码可读性同样重要，声明left和right
            ListNode left = null;
            ListNode right = null;
            if (fastNode == null)
            {
                right = slowNode;
                left = guardNode;
            }
            else
            {
                right = slowNode.next;
                left = guardNode;
            }

            //step3: 遍历左右链表并比对相应的值
            while (right != null)
            {
                if (right.val != left.val)
                {
                    return false;
                }
                else
                {
                    right = right.next;
                    left = left.next;
                }
            }

            return true;
        }
```
