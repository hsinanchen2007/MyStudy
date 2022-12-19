### 解题思路
此处撰写解题思路
将此题作为带头结点的链表来做，最终的循环结束以后head节点依然在最前面，后面的已经全部反转，最后将第一个节点放到最后面即可。
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
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null){//只有一个节点或者没有节点时直接返回head
            return head;
        }

        ListNode tt=head;//tt始终指向最新插入的节点
        ListNode temp=head.next;
        ListNode rearNode=head;
       
        while (true) {
            rearNode= head;//里层while结束以后rearNode记录倒数第二个节点
            while (true){
                if (rearNode.next.next==null){
                    break;
                }else {
                    rearNode=rearNode.next;
                }
            }
            //rearNode.next表示当前最后一个节点，如果当前最后一个节点是最初的第一个时
            //就表示已经全部反转成功，退出循环
            if (rearNode.next==temp){
                break;
            }
            //将最后一个节点放到上一次插入的节点之后
            rearNode.next.next=tt.next;
            tt.next=rearNode.next;
   
            tt=tt.next;//每次外层循环完tt就后移一位，所以tt始终指向最新插入的节点
            rearNode.next=null;//将最后一个节点的next置空
        }
        ListNode re=head.next;
        rearNode.next.next=head;
        head.next=null;
        return re;
    }
}
```