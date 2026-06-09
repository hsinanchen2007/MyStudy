### 解题思路
执行用时 :
0 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
36.3 MB
, 在所有 java 提交中击败了
56.29%
的用户

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
    public void deleteNode(ListNode node) {
         ListNode now=null;
        while(node.next!=null){
            node.val=node.next.val;
            now=node;
            node=node.next;
        }
       
            now.next=null;
        
    }
}
```