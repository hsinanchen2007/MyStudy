### 解题思路
先用快慢指针找到中间的链表节点slow，再对slow后面的链表原地反转，依次比较反转后的链表和初始链表在slow之前的链表的值。
![image.png](https://pic.leetcode-cn.com/a633120097b35935d986e950ef7d3fce78d4ce7400c6a29f0b378fc1ea4e0878-image.png)


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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null)
            return true;
        ListNode fast = head;
        ListNode slow = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        //从slow后面的链表逆序
        ListNode node = slow.next;
        ListNode curNode = node;
        slow.next = null;
        ListNode pre = null;
        ListNode nextNode = null;
        while(curNode != null){
            nextNode = curNode.next;
            curNode.next = pre;
            pre = curNode;
            curNode = nextNode;
        }
        ListNode temp = head;
        boolean flag = true;
        while(pre != null){
            if(temp.val != pre.val){
                flag = false;
                break;
            }
            temp = temp.next;
            pre = pre.next;
        }
        return flag;
    }
}
```