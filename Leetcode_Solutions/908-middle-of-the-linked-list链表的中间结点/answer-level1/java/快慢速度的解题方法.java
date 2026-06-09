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
 //f的速度是s的速度的2倍，当f或者f的next到了终点的时候   s刚好就是中间节点
class Solution {
    public ListNode middleNode(ListNode head) {
          ListNode f = head;
          ListNode s = head;
          while(f!=null && f.next!=null){
              f = f.next.next;        
              s = s.next;
          }      
          return s;

    }
}
```