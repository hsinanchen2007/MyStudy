### 解题思路
使用两个虚假头结点，同分割链表解题思路相同

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
    public ListNode oddEvenList(ListNode head) {
        //使用两个虚假头结点
        int index=0;
        ListNode lhead=new ListNode(0);
        ListNode rhead=new ListNode(0);
        ListNode lnode=lhead;
        ListNode rnode=rhead;
        ListNode node=head;
        while(node!=null){
            if(index%2==0){
                lnode.next=node;
                lnode=lnode.next;
            }else{
                rnode.next=node;
                rnode=rnode.next;
            }
            node=node.next;
            index++;
        }

        rnode.next=null;
        lnode.next=rhead.next;

        return lhead.next;

    }
}
```