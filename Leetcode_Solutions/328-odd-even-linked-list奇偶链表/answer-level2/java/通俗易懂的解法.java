### 解题思路

head : 奇数头节点
 // prenew：偶数头节点

 // pre:奇数尾节点
 // next：偶数尾节点 

四个节点来回切换，画图太麻烦了，反正都是四个节点


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
    public ListNode oddEvenList(ListNode head) {
        if (head == null) {
            return head;
        }
 // head : 奇数头节点
 // prenew：偶数头节点

 // pre:奇数尾节点
 // next：偶数尾节点

        ListNode pre = head;
        ListNode prenew = head.next;
        ListNode next = head.next;
        ListNode nextnew = null;
        if (next != null) {
            nextnew = next.next;
        }
        while (nextnew != null){
            pre.next = nextnew;
            next.next = nextnew.next;
            nextnew.next = prenew;
            pre = pre.next;
            if (next.next == null || next.next.next == null) {
                break;
            }
            next = next.next;
            nextnew = next.next;
        }
        return head;
    }
}
```

继续学习，看下各位大牛们怎么解决