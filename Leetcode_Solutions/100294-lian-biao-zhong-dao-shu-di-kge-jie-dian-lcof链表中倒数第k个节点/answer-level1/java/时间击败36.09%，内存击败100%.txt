### 解题思路
1.第一次遍历，求出节点数目count。2.计算count-k，第二次遍历到第count-k个节点，返回该节点。

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
        int count=0;
        ListNode temp = head;
        while(temp != null){
            count++;
            temp = temp.next;
        }
        int j=count-k;
        while(j!=0){
            head = head.next;
            j--;
        }
        return head;
    }
}
```