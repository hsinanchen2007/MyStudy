### 解题思路
总体上考虑三种情况
1.链表只有一个节点：逆序就是其本体，直接返回head
2.链表有两个节点：
    head.next.next = head; 
    head = head.next; 
    head.next.next = null
3.链表有三个以上节点：
先将head置空，作为逆序后链表的最后一个节点
当former为空时循环截止：
    使用快慢指针former、latter一个一个搬运
还需要把最后一个latter接入逆序的链表做head
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
    public ListNode reverseList(ListNode head) {
        ListNode latter = head,former = head;
        //如果头结点为空或者链表只有一个节点，都直接返回head
        if (head == null || head.next == null ){
            return head;
        }else if ( head.next.next ==null ){        //链表有两个节点
            head.next.next = head;
            head = head.next;
            head.next.next = null;
            return head;
        }else {                                    //链表有三个以上节点
            latter = head.next;                    //使用快慢指针
            former = head.next.next;

            head.next = null;                      //先将头节点的next置空
            while (former != null) {          //只要右边的节点
                latter.next = head;
                head = latter;
                latter = former;
                former = former.next;
            }
            latter.next = head;
            head = latter;
        }
        return head;
    }
}
```