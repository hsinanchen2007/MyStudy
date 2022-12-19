### 解题思路
首先遍历一遍求出链表长度，然后建立数组，再遍历一遍链表把元素逆序放入数组中。

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
        int n=0;
        ListNode p=head;
        while(p!=null)
           {
                n++;
                p=p.next;
           }

        int[] s=new int[n];
        p=head;
        for(int i=n-1;i>=0;i--)
            {
                s[i]=p.val;
                p=p.next;
            }
        return s;
    }
}
```