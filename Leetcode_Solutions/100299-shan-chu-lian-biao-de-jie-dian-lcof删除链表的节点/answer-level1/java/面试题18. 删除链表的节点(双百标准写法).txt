### 解题思路
见注释，有两个小地方注意：
1.假如原链表中有重复值，需要注意跳出循环，只删除第一个
2.如果删除节点是尾节点（item.next），不需要判断，因为item.next.next=null，直接将其覆盖尾节点就行了

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
    public ListNode deleteNode(ListNode head, int val) {
        if(head==null)return head;//判空
        ListNode item=new ListNode(-1);//虚拟头节点
        item.next=head;
        ListNode p=item;//虚拟头指针
        while(p.next!=null){
            if(p.next.val==val){
                p.next=p.next.next;
                break;//只删除第一个值=val的节点，后面的重复值不删
            }else {
                p=p.next;
            }
        }
        return item.next;
    }
}
```