### 解题思路
非递归方法是比较简单的思路，但消耗内存较大
首先建立两个链表tem，还有flag，flag用于记录链表tem表头，操作是将tem对象地址赋给flag
然后逐一比较将l1，l2的d各个节点插入tem，最后通过flag.next删除tem头结点且返回
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
    if(l1==null){return l2;}
    if(l2==null){return l1;}
    ListNode tem=new ListNode(0);
    ListNode flag=tem;
    while(l1!=null&l2!=null){
     if(l1.val<l2.val){
        tem.next=l1;
        l1=l1.next;
    }else {
        tem.next=l2;
        l2=l2.next;
    }
    tem=tem.next;
    }
    if(l1!=null){tem.next=l1;}
    if(l2!=null){tem.next=l2;}
   return flag.next;
}}
```