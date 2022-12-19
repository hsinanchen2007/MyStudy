### 解题思路
利用两个指针p1， p2

p1确定当前的值，p2去搜寻下一个不同值，重复这个过程直至结束，注意指针到链表尾为null的情况

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
        if(head==null){return head;}
        ListNode p1 = head;
        ListNode p2 = head;

        while(p1!=null&&p2!=null){
            int current = p1.val;
            //System.out.println(current);
            while(p2!=null&&p2.val==current){
                p2=p2.next;
            }
            p1.next=p2;
            p1=p2;
        }

        return head;
    }
}
```