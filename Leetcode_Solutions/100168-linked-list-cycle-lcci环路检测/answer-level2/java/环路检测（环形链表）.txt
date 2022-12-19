### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        //哈希表法
        Set<ListNode> set=new HashSet<>();
        while(head!=null)
        {
            if(set.contains(head))
                return head;
            set.add(head);
            head=head.next;
        }
        return null;
    }
}
```