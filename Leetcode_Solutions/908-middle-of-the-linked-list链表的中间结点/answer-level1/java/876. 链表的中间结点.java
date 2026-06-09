### 解题思路
数组存储结点，然后就能很清楚的获取中间结点。
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
        ListNode[] arry=new ListNode[100];
        int index=0;
        while(head!=null){
            arry[index++]=head;
            head=head.next;
        }
        return arry[index/2];
    }
}
```