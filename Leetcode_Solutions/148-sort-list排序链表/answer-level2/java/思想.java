### 解题思路
此处撰写解题思路
我的思路:
    首先判断链表的内容是否为空，如果为空的话直接返回Null
    再根据比较排序法，用前面一个的值和后面一个的值进行比较，如果后面的
值小于前面的值，那么前面的一个值放到后面的位置，将后面的位置放入到前面的
位置；
最后返回的就是头节点head，ok;
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
    public ListNode sortList(ListNode head) {
        ListNode temp=head;
        if(head==null)return null;
        while(temp.next!=null){
            ListNode cur=temp.next;
            while(cur!=null){
                if(temp.val>cur.val){
                    int k=temp.val;
                    temp.val=cur.val;
                    cur.val=k;
                }
                cur=cur.next;
            }
            temp=temp.next;
        }
        return head;
    }
}
```