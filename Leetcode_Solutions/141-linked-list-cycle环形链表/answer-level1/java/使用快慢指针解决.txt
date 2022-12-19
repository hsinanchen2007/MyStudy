### 解题思路
1.此时主要考虑到有效的循环链表不会出现null节点
2.只要两个指针最终指向同一个节点 就说明该链表是循环链表
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
        if(head==null || head.next==null ||head.next.next==null){
            return false;
        }
        ListNode slow=head;
        ListNode fast=head;
        //创建两个指针 快指针的移动速度是慢指针的两倍，如果是循环链表时，快指针最终会与慢指针指向同一个节点
        while(slow.next!=null&&fast.next!=null&&fast.next.next!=null){
            if(slow.next==fast.next.next){
                return true;
            }
            //移动指针
            slow=slow.next;
            fast=fast.next.next;
        }
        //一旦出现为null的情况 则可以判断该链表非循环链表
        return false;
    }
}
```