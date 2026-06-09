### 解题思路
java 双指针
1.定义一个虚结点，方便返回链表，而且可将头结点和其他结点同等对待
2.定义前一结点prev和当前结点curr，无重复情况一个一个往后跳
一旦出现重复，curr整个跳过，prev.next指向跳过后的curr
3.最终返回dummy.next

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head ==null || head.next==null) return head;
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        prev.next = head;
        ListNode curr = head;
        while(curr!=null && curr.next!=null){
            if(curr.val==curr.next.val){
                while(curr!=null && prev.next.val ==curr.val){
                    curr = curr.next;
                }
                prev.next = curr;
            }
            else{
                prev = prev.next; 
                curr = curr.next;
            } 
        }
        return dummy.next;
    }
}
```