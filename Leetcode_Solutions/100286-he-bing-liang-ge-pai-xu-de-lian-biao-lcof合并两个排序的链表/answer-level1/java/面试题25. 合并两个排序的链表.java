### 解题思路
第一步：构建虚假链表头
第二步：遍历两个链表，将较小数据添加至虚假链表
第三步：将没有遍历完的链表添加至虚假链表

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode node=new ListNode(0);
        ListNode tmp=node;
        ListNode node1=l1;
        ListNode node2=l2;
        while(node1!=null&&node2!=null){
            if(node1.val<=node2.val){
                tmp.next=node1;
                node1=node1.next;
            }else{
                tmp.next=node2;
                node2=node2.next;
            }
            tmp=tmp.next;
        }
        tmp.next=(node1!=null)?node1:node2;

        return node.next;
    }
}
```