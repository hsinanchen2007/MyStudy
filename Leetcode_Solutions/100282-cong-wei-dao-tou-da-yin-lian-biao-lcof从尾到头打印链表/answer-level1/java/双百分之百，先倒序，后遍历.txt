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
class Solution {
    public int[] reversePrint(ListNode head) {
        int[] res= new int[0];
        int len=1;
        if(head==null){
            return res;
        }
        ListNode one=head;
        ListNode two =head;
        ListNode thr=head.next;
        one.next=null;
        while(thr!=null){
            two=thr;
            len++;
            thr=thr.next;
            two.next=one;
            one=two;
        }
        res= new int[len];
        int i=0;
        while(two!=null){
            res[i]=two.val;
            i++;
            two=two.next;
        }
        return res;
    }
}
```