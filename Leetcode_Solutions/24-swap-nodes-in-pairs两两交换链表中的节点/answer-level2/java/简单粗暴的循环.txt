### 解题思路
我不太会递归,只会循环.
下面有两种写法,写法2更为巧妙

### 代码

+ 我的代码,下面有优化代码
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
    public ListNode swapPairs(ListNode head)
    {
        /**
         * start,end是需要交换的值.
         * e1Prev就表示start的前一个节点,默认为null,因为start默认为头节点.
         * 所以交换完之后,`e1Prev=start;start=start.next;`
         */
        ListNode e1Prev = null, start = head, end;
        while (start != null && (end = start.next) != null)
        {
            start.next = end.next;
            end.next = start;
            if (e1Prev == null)
            {
                /*头节点改变*/
                head = end;
            } else
            {
                /*头节点不变*/
                e1Prev.next = end;
            }
            e1Prev = start;
            start = start.next;
        }

        return head;
    }
}
```

+ 优化代码,加一个哑节点
```java
    public ListNode swapPairs(ListNode head)
    {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        for (ListNode temp = dummy, start = temp.next, end;
             start != null && (end = start.next) != null;
             temp = start)
        {
            temp.next = end;
            start.next = end.next;
            end.next = start;
        }

        return dummy.next;
    }
```