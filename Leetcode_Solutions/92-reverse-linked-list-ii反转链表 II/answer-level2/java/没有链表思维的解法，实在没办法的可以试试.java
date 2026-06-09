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
class Solution {
     List<Integer> list = new ArrayList<>();

    public ListNode reverseBetween(ListNode head, int m, int n) {
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }

        int[] results = new int[list.size()];

        for (int i = 0; i < list.size(); i++) {
            results[i] = list.get(i);
        }
        int begin = m - 1;
        int end = n - 1;

        while (end > begin) {
            int temp = results[begin];
            results[begin] = results[end];
            results[end] = temp;
            end--;
            begin++;
        }
        ListNode result = new ListNode(results[0]);
        ListNode current = result;
        for (int i = 1; i < results.length; i++) {
            current.next = new ListNode(results[i]);
            current = current.next;
        }
        return result;
    }
}
```