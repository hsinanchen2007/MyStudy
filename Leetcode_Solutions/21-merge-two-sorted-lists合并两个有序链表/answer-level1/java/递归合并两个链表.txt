### 解题思路
参考了一下题解，发现自己对递归十分不熟练
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