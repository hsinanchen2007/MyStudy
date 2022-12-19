### 解题思路
一共分为三步：
* 求出两个链表的长度
* 对长链表做裁剪，使得两个链表一样长
* 两个指针指向链表头，并依次遍历，相等的点即为相交点。

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
        int l1 = getLen(headA);
        int l2 = getLen(headB);
        ListNode r1 = headA;
        ListNode r2 = headB;
        if(l1>l2){
            r1 = getStart(headA, l1-l2);
        }
        else{
            r2 = getStart(headB, l2-l1);
        }
        while(r1!=r2){
            r1 = r1.next;
            r2 = r2.next;
        }
        return r1;

    }
    public int getLen(ListNode head){
        int l = 0;
        while(head!=null){
            l++;
            head=head.next;
        }
        return l;
    }
    public ListNode getStart(ListNode head, int step){
        for(int i =0;i<step;i++){
            head = head.next;
        }
        return head;
    }
}
```