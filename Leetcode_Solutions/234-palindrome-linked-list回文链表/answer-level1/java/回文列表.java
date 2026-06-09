### 解题思路
看到这题，首先想到要是能拿到最后一个节点就好了，然后再想到如何从最后一个节点返回上一级节点呢，就是用栈，也就是递归。
首先通过`next`指针不断的指向下一级的节点，一直到最后得到最后一个节点，如果最后一个节点和首节点相同，则返回首节点的下一个节点，也就是`head.next`，此时由于函数返回，`next`节点可以回到上一级节点，不断持续这个过程，相当于遍历了两遍链表。

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
    public ListNode isPalindrome(ListNode head, ListNode next){
        if(next == null)return head;
        ListNode tmpHead = isPalindrome(head, next.next);
        if(tmpHead == null)return null;
        else if(tmpHead == next || tmpHead.val == next.val){
            return tmpHead.next;
        }
        return null;
    }

    public boolean isPalindrome(ListNode head) {
        if(head == null)return true;
        return isPalindrome(head, head.next) != null;
    }
}

```