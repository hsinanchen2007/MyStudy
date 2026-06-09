[leetcode86](https://leetcode-cn.com/problems/partition-list/submissions/)

* 先进行统一处理：让头部以一个小于x的值作为head。
* 对于这种题优先考虑交换，然后考虑构造新的。

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
    public ListNode partition(ListNode head, int x) {
        if(head == null) return head;
        ListNode current = head,smallerTail;
        if(head.val >= x){  //统一处理，让头部先小于x
            while(current.next != null && current.next.val >= x){
                current = current.next;
            }
            if(current.next == null) return head;
            else{
                ListNode tmp = current.next;
                current.next = current.next.next;
                tmp.next = head;
                head = tmp;
            }
        }
        smallerTail=head;
        //要是前面一步进行了转换，那么smallerTail.next.val < x不成立，也就是说，下面的循环只会在
        //smallerTail=current的条件下进行，所以不会出现空指针异常。
        while(smallerTail.next != null && smallerTail.next.val < x){  
            smallerTail=smallerTail.next;
            current=current.next;
        }
        while(current.next != null){  //出现小的直接提到前面来。
            if(current.next.val < x){
                ListNode tmp = smallerTail.next;
                smallerTail.next=current.next;
                current.next=current.next.next;
                smallerTail.next.next=tmp;
                smallerTail=smallerTail.next;
            }else
                current=current.next;
        }
        return head;
    }
}
```

