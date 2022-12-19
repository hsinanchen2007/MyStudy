### 解题思路
时间复杂度为**O(n)**,空间复杂度为**O(1)**

定义一个标识符flag，第一种情况：如果node.val == node.next.val，node节点向后移，并且flag记为正数；第二种情况为node.val != node.next.val，但是当flag为正时，需要将当前节点抹去，并将flag重置为0.如果flag为0，节点向后移；

这样遍历整个链表，如果最后几个节点是相同的，会保留一个节点，显然这样的的结果是不对的，但是此时我们可以知道flag的值，根据flag的值我们再去遍历一遍链表，将链表的尾节点做删除操作。

时间复杂度为O(n),空间复杂度为O(1)

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

        if(head==null || head.next==null) return head;
        ListNode node = head;
        int flag=0;
        int a = 0;
        while(node.next!=null){
            if(node.val == node.next.val){
                flag++;
                node.next = node.next.next;
                
            }else if(flag>0){
                node.val = node.next.val;
                node.next = node.next.next;
                flag=0;
            }else{
                node = node.next;
            }
            
        }
        ListNode result = head;
        if(flag>0){
            if(result.next==null){
                return null;
            }
            while(result.next!=null){
                if(result.next.next==null){
                    result.next=null;
                    break;
                }
                result = result.next;
            }
        }
        return head;
    }
}
```