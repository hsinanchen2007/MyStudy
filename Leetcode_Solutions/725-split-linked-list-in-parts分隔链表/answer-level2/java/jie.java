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
   public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] result = new ListNode[k];
        ListNode find = root;
        int count = 0;
        while(find != null) {
            count++;
            find = find.next;
        }
        int a = count / k;
        int b = count % k;
        int start = 0;
        while(start < k) {
            result[start] = root;
            if (root == null){
                result[start++] = root;
                continue;
            }
            ListNode cur = result[start];
            int len = a + (b-- > 0 ? 1 : 0);
            while(len-- > 1) {
                root = root.next;
                cur = cur.next;
            }
            root = root.next;
            cur.next = null;
            start++;
        }
        return result;
    }
}
```