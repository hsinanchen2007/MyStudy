### 解题思路
算是双指针吧

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
    public ListNode middleNode(ListNode head) {
        ListNode cur=head;
        int length=1;
        while(cur.next!=null){
            cur=cur.next;
            length++;
        }
        cur=head;
        for(int i=0;i<length/2;i++){
            cur=cur.next;
        }
        return cur;
    }
}
```