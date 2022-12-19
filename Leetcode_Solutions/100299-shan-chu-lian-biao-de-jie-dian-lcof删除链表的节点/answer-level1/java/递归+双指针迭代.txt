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
    //递归做法
    public ListNode deleteNode(ListNode head, int val) {
        if(head == null){
            return head;
        } 
        if(head.val == val){
            return head.next;
        }
        ListNode node = deleteNode(head.next, val);
        head.next = node;
        return head;
    }
    /*
    public ListNode deleteNode(ListNode head, int val) {
        if(head == null){
            return head;
        } 
        if(head.val == val){//分两种情况，头结点找到，直接返回
            return head.next;
        }   
        ListNode pre = null;
        ListNode cur = head;       
        while(cur.val != val){//头结点不满足，前后指针迭代
            pre = cur;
            cur = cur.next;
        }
        pre.next = pre.next.next;
        return head;
    }*/
}
```