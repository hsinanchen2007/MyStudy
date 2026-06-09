### 解题思路
此处撰写解题思路
定义一个数组来存放循环取出来的节点，然后根据i计数得到的总结点数，得到倒数第k个节点。
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
        ListNode[] p = new ListNode[100];
        int i=0;
        while(head!=null){
            p[i] = head;
            head = head.next;
            i++;
        }
        return p[i-k];
    }
}
```