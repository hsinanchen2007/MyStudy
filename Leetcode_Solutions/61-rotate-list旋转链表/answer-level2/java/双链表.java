[leetcode61](https://leetcode-cn.com/problems/rotate-list/)

* 将链表看成环形的，找到倒数第K个做头部即可。

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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return  head;
        ListNode first = head, second = head;
        int count = 0;
        while(k>0){
            if(first == null){
                first = head;
                k=k%count;//很有必要。
                if( k == 0)
                    break;  //及时跳出循环
            } 
            first=first.next;
            k--;
            count++;
        }
        if(first == head || first == null) return head;
        while(first.next != null){
            first = first.next;
            second = second.next;
        }
        first.next = head;
        head = second.next;
        second.next= null;
        return head;
    }
}
```

