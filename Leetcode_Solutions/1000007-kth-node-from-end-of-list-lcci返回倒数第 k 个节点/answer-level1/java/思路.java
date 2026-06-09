### 解题思路
此处撰写解题思路
我的思路:
    先统计一下原来链表的长度，然后用一个辅助的链表，通过原始链表的长度减去k，
然后用循环遍历到长度减去k的长度
循环完之后就是那个值，之后就返回出来那个值!
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
    public int kthToLast(ListNode head, int k) {
        int len=0;
        ListNode temp=head;
        ListNode temp1=head;
        while(temp!=null){
            len++;
            temp=temp.next;
        }
        
        for(int i=0;i<len-k;i++){
            temp1=temp1.next;
        }
        return temp1.val;
    }
}
```