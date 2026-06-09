思路非常清晰，画图更加容易理解
直接来个进阶版的代码吧，定义快慢指针，慢指针边走边翻转链表，最后判断前半段和后半段是否相同即可，需要注意链表为奇数个还是偶数个的问题，处理起来稍微有点不同，不懂的话画个图就行了
```java
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null){
            return true;
        }
        ListNode slow = head;
        ListNode fast = head;
        ListNode newNode = null;
        while (fast.next != null && fast.next.next != null) {
            //慢指针前进的过程中还需要反转链表
            fast = fast.next.next;
            ListNode nextNode = slow.next;
            slow.next = newNode;
            newNode = slow;
            slow = nextNode;
        }
        if (fast.next == null) {
            //链表为奇数个
            ListNode newHead = slow.next;
            while (newHead != null && newNode != null) {
                if (newHead.val != newNode.val) {
                    return false;
                }
                newHead = newHead.next;
                newNode = newNode.next;
            }
        } else {
            //链表为偶数个
            ListNode newHead = slow.next;
            slow.next = newNode;
            while (slow != null && newHead != null) {
                if (slow.val != newHead.val) {
                    return false;
                }
                slow = slow.next;
                newHead = newHead.next;
            }
        }
        return true;
    }
}
```