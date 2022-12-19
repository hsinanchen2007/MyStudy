### 解题思路
创建两个新的空链表，分别用来存储小于x以及大于等于x的节点。然后对原链表进行遍历，将相应的节点放到各自的链表中。

需要注意一点，对于像 [1] x=2 这样的用例，还需要判断一下，是否列表2用到了。

### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode Partition(ListNode head, int x) {        
        ListNode current = head;

        ListNode list1 = new ListNode(0); list1.next = head;
        ListNode list2 = new ListNode(0); list2.next = head;
        ListNode head1 = list1;
        ListNode head2 = list2;
        
        bool usedList2 = false;
        while(current != null)
        {
            if(current.val < x)
            {
                list1.next = new ListNode(current.val);
                list1 = list1.next;        
            }
            else
            {
                list2.next = new ListNode(current.val);
                list2 = list2.next;
                usedList2 = true;
            }

            current = current.next;
        }

        if(usedList2)
        {
            list1.next = head2.next;
        }

        return head1.next;
    }
}
```