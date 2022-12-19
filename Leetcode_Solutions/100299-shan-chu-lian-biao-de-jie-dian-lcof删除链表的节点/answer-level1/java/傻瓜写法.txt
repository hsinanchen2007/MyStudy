### 解题思路
此处撰写解题思路
执行用时 :
0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :
41.2 MB, 在所有 Java 提交中击败了100.00%的用户
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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode resHead = head;
        while(head!=null){
            ListNode node = head.next;
            //首节点是要删除的
            if(head.val == val){
                resHead = node;
                return resHead;
            }
            //首节点不是
            if(node !=null && node.val==val){
                head.next = node.next;
                return resHead;
            }
            head = node;
        }
        return resHead;
    }
}
```