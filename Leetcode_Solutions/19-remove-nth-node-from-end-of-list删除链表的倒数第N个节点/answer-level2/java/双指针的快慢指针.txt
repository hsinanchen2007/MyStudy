### 解题思路


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
    public ListNode removeNthFromEnd(ListNode head, int n) {
          if (head==null) {
            return null;
        }

        ListNode res = null;
        ListNode p1 = head;
        ListNode p2 = null; //需要删除的指针
        ListNode p3 = null;
        //使用双指针，其实是一个快慢指针，让你理解倒数这个概念

        int i=0;
        while (p1!=null) {
            if(i==n) p2 = head;

            p1 = p1.next;

            if (p2!=null) {
                p3 = p2;
                p2 = p2.next;
            }
            i++;
        }

        //说明没有到最后一个还没有到p2，所以删除头节点
        if(i<=n){
            p2 = head;
            head = head.next;
            p2.next = null;
        }else{
            //按照正常的删除,需要删除p2
            p3.next = p2.next;
            p2.next = null;
        }

        return head;

    }
}
```