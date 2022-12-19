### 解题思路
两个指针都从head开始，第一个先走k， 保持他们之间的距离为k。
当第一个走到尾的时候， 第二个的位置就是我们要找的倒数第k个。

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head == null) return null;
        ListNode first = head, second = head;
        int length= 0;
        while(first!=null){
            first = first.next;
            length++;
            if(length>k){
                second = second.next;
            }
        }
        if(length<k-1) return null;
        return second;

    }
}
```