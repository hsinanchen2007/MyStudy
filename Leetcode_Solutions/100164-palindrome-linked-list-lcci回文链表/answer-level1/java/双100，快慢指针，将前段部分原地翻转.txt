### 解题思路
此处撰写解题思路

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
        if(head == null){
            return true;
        }
        ListNode slow = head; //慢指针
        ListNode fast = head; //快指针
        ListNode nexttemp = null; //当前指针的下一个指针，翻转用
        ListNode cur = head; //当前节点，翻转用
        ListNode reverseHead = head;  //新定一个节点，作为slow的翻转节点
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

            nexttemp = cur.next;     //先记录cur的下一个节点，以防翻转后找不到下一个节点
            if(cur != head){         //r如果cur= head时不需要翻转
                cur.next = reverseHead;
                reverseHead = cur;
            }
            cur = nexttemp;
        }
        if(fast != null){    //fast不为空是个数是奇数，slow需要往后移动一位
            slow = slow.next;
        }

        while(slow != null && reverseHead != null){
            if(slow.val != reverseHead.val){
                return false;
            }
            slow = slow.next;
            reverseHead = reverseHead.next;
        }

        return true;
    }
}
```