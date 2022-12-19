### 解题思路
此处撰写解题思路
可能用那个双指正会一点吧
执行用时 :
1 ms
, 在所有 Java 提交中击败了
29.64%
的用户
内存消耗 :
37.5 MB
, 在所有 Java 提交中击败了
100.00%
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
    public ListNode getKthFromEnd(ListNode head, int k) {
        int tot = 0;
        ListNode res = null;
        List<ListNode> tmp = new ArrayList<>();
        while (head != null){
            tot++;
            tmp.add(head);
            head = head.next;
        }
        res = tmp.get(tot - k);
        return res;
    }
}
```