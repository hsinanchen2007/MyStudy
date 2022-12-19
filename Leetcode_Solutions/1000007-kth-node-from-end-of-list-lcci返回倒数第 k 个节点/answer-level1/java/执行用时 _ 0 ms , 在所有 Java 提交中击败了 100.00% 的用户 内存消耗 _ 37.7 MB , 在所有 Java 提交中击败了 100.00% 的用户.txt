### 解题思路
求出长度后，遍历获得。

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
    public int kthToLast(ListNode head, int k) {
        ListNode node = head;
        ListNode pre = head;
        int m=0,n= 0,i=0;
        while(node != null){
            ++n;
            node = node.next;
        }
        while(pre != null){
            ++i;
            if(i == (n-k+1)){
                m = pre.val;
            }
            pre = pre.next;
        }
        return m;
        
    }
}
```