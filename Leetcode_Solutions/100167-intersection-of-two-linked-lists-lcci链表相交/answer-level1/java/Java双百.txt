![WechatIMG1.jpeg](https://pic.leetcode-cn.com/2bd62ad4face8a51bb505fe33c753e25de5a886e266b13d76582c725c0d8d66f-WechatIMG1.jpeg)

### 解题思路
代码写的比较啰嗦，为的是更好地理解。两个指针先走到各自的倒数第一个链表。如果不相等直接返回null。然后判断各自链表长度，如果headA比headB长n，让headA先走A步，然后headA和headB再一块走。最后相等的节点就是相交点。


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null)
            return null;
        int lengthA = 1;
        int lengthB = 1;
        ListNode curA = headA;
        ListNode curB = headB;
        while(curA.next != null){
            lengthA++;
            curA = curA.next;
        }
        while(curB.next != null){
            lengthB++;
            curB = curB.next;
        }
        if(curA == curB && curA == null || curA != curB)
            return null;
        if(lengthA >= lengthB){
            //headA先走lengthA - lengthB步
            int n = lengthA - lengthB;
            while(n-- != 0)
                headA = headA.next;
            while(headA != headB){
                headA = headA.next;
                headB = headB.next;
            }
            return headA;
        }else{
            //headB先走
            int n = lengthB - lengthA;
            while(n-- != 0)
                headB = headB.next;
            while(headA != headB){
                headA = headA.next;
                headB = headB.next;
            }
            return headA;
        }
    }
}
```