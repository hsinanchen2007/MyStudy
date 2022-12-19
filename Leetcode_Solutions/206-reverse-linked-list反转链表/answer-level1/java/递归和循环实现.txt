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
//举个实例1->2->3->4->5->null
class Solution {
    //递归 
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }
        //最后一次返回的结果listNode=5->null,head=4->5->null
        ListNode listNode=reverseList(head.next);
        //这一步从4->5->null变为4->5->4->5->null;
        head.next.next=head;
        //这一步变为4->5->4->null;
        head.next=null;
        //所以listNode变为5->4->null,链表被反转了
        return listNode;
    }
    //循环
    public ListNode reverseList(ListNode head) {
        ListNode listNode=null;
        //1->2->3->4->5->null;
        ListNode temp=head;
        while(temp!=null){
            //next=2->3->4->5->null;
            ListNode next=temp.next;
            //temp变为1->null;
            temp.next=listNode;
            //listNode从null变为1->null
            listNode=temp;
            //temp变为2->3->4->5->null;
            temp=next;
        }
        //重复循环listNode变为5->4->3->2->1->null;
        return listNode;
    }
}
```