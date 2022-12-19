### 解题思路
把结点放到数组里，长度除以二的位置的结点就是要找的那个结点

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
 import java.util.ArrayList;
class Solution {
    public ListNode middleNode(ListNode head) {
        ArrayList<ListNode> list = new ArrayList<>();
        ListNode p = head;
        while(p != null){
            list.add(p);
            p = p.next;
        }
        return list.get(list.size()/2);
    }
}
```