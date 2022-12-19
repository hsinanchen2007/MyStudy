先对1->2->3->4->5进行反转
注意反转的时候记下链表的长度,假定为length

n=n%length 就是反转后链表要删除的第几个节点
注意如果n=0,那么手动将n赋值为length,表明是要删除最后一个节点
做了节点删除后，再将链表反转回来。

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

 //先反转链表
    public ListNode reverseNode(ListNode head, AtomicInteger length) {
        ListNode root = head;
        ListNode firstNode = null;
        ListNode currentNode = null;
        while (root != null) {
            firstNode = new ListNode(root.val);
            firstNode.next = currentNode;
            currentNode = firstNode;
            root = root.next;
            length.addAndGet(1);
        }
        return currentNode;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(n==0){
            return head;
        }
        AtomicInteger length = new AtomicInteger(0);
        ListNode reverseNode = reverseNode(head,length);
        //真实要寻找的步骤
        n = n%length.get();
        if(n==0){
            n = length.get();
        }
        int index = 1;
        ListNode head0 = reverseNode;
        ListNode prevNode = null;
        while(index<n){
            prevNode = head0;
            head0 = head0.next;
            index++;
        }
        if(head0==reverseNode){
            return reverseNode(reverseNode.next,length);
        }else if(head0==null){
            prevNode.next = null;
            return reverseNode(reverseNode,length);
        }else{
            prevNode.next = head0.next;
            return reverseNode(reverseNode,length);
        }
    }
}
```