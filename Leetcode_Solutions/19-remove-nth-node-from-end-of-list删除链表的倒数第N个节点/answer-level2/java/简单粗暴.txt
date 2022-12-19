### 解题思路
1. 设置两个变量,count确定元素个数,i用来标记要删除元素的下标位置,当`i=count-n`就是我们要删除的元素.
2. 变量所有元素,求count
3. 变量链表,这里主要两个变量:
   + e用作遍历使用,表示当前节点
   + prev表示当前节点的上一个节点(主要用来判断是否为头节点)
4. 所以初始化e=head,而head没有上一个节点,所以prev=null.
5. 如果是我们要删除的节点,判断是否为头节点,做两种处理
6. 如果不是要删除的节点,继续遍历.
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n)
    {
        int count = 0;/*总元素个数*/
        int i = 0;/*要删除的元素下标*/
        for (ListNode e = head; e != null; count++)
        {
            e = e.next;
        }

        for (ListNode e = head, prev = null; e != null; i++)
        {
            /*确定删除节点*/
            if (i == (count - n))
            {
                if (prev == null)
                {
                    /*头节点*/
                    head = e.next;
                } else
                {
                    /*非头节点*/
                    prev.next = e.next;
                }
                return head;
            }
            prev = e;
            e = e.next;
        }
        return head;
    }
}
```

+ 使用哑节点进行优化
```java
    public ListNode removeNthFromEnd(ListNode head, int n)
    {
        int count = 0;/*总元素个数*/
        int i = 0;/*要删除的元素下标*/
        for (ListNode e = head; e != null; count++)
        {
            e = e.next;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        for (ListNode prev = dummy, e = prev.next; e != null; i++)
        {
            if (i == ((count - n))
            {
                /*找到要删除的元素*/
                prev.next = e.next;
                break;
            }
            /*指向下一个节点*/
            prev = e;
            e = e.next;
        }
        return dummy.next;
    }
```