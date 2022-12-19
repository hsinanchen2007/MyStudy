### 解题思路
![2020-03-02_155501.jpg](https://pic.leetcode-cn.com/75c7fc6302ebc76c91a6c126ab798c711f52d610c7956bb07bb8309e41260c56-2020-03-02_155501.jpg)
使用递归筛选

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
    HashSet<Integer> list = new HashSet<>();
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null) {
            return head;
        }
        if(!list.contains(head.val)) {
            list.add(head.val);
            head.next = removeDuplicateNodes(head.next);
            return head;
        } else {
            return removeDuplicateNodes(head.next);
        }
    }
}
```