### 解题思路
判断有环，可以使用两个指针，分别为快指针和慢指针，其中快指针每次走两个节点，慢指针每次走一个节点，当快指针指向空值时，这个单链表就一定没有环(快指针更快地到达链表尾部)，当快指针指向的节点和慢指针是一样的时候，那么表明当前的链表是有环的，因为只要有环，那么快指针就一定会和慢指针交汇

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null){
            return false;
        }else {
            ListNode fast = head.next.next;
            ListNode slow = head.next;
            while (true){
                if (fast == null){
                    return false;
                }else {
                    //将快指针和慢指针的每一个元素都进行比较
                    fast = fast.next;
                    slow = slow.next;
                    if (fast == null){
                        return false;
                    }else {
                        if (fast == slow){
                            return true;
                        }else {
                            fast = fast.next;
                            if (fast == null){
                                return false;
                            }else {
                                if (fast == slow){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
```