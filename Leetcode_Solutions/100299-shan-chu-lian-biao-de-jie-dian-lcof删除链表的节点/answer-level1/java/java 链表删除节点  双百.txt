### 解题思路
    遍历寻找删除的节点，然后将节点的前一个节点的next指向删除节点的下一个节点。
    但要考虑到特殊情况，例如删除头结点或者删除尾结点时的情况

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
        if(head==null){
            return null;
        }
        ListNode prenode=head,node = head;
        while(node!=null){
            if(node.val==val){
                break;
            }
            prenode=node;
            node=node.next;
        }
        //删除尾结点
        if(node==null){
          prenode.next=null;
        }else{
            //删除头结点
            if(node==head){
                head=node.next;
            }else{
                //正常情况
                prenode.next = node.next;
            }
            
        }
        
        return head;
    }
}
```