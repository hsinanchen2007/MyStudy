### 解题思路
递归思路比较简单：其实就是一个循环中，每次比较两个链表头节点val的大小，头节点比较下的链表，头节点向后移动一位，然后再次把两个链表当作参数传入递归函数，直到遍历完其中一个链表；其实就是每次取出两个链表中的最小值，“扣”下来，再对两个链表执行“扣”操作；

迭代：其实跟递归思路差不多，只是实现方式不同，迭代是用一个指针每次记录两个链表的最小值，就是用指针每次指向较小的节点，直到两个链表中有一个遍历完，遍历完之后需要判断是那个遍历完了，因为还需要指向没有遍历完的链表的其他节点

### 代码

递归实现代码：
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
        if(l1==null){
            return l2;
        }else if(l2==null){
            return l1;    
        }else if(l1.val < l2.val){
            l1.next=mergeTwoLists(l1.next,l2);
            return l1;
        }else{
            l2.next=mergeTwoLists(l1,l2.next);
            return l2;
        }
    }
}
```

迭代实现代码：
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
        ListNode prehead=new ListNode(-1);
        ListNode prev=prehead;
        while(l1!=null&&l2!=null){
            if(l1.val<l2.val){
                prev.next=l1;
                l1=l1.next;
            }else{
                prev.next=l2;
                l2=l2.next;
            }
            prev=prev.next;
        }
        prev.next=l1 == null?l2:l1;

        return prehead.next;
    }
}
```
