### 解题思路
利用java的hashset不能有重复值这一特点，当发现重复时就说明有环

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
    public boolean hasCycle(ListNode head) {
        Set<ListNode> set = new HashSet<ListNode>();
        ListNode pos = head;
        int beforeSize, afterSize = 0;
        while(pos != null){
            beforeSize = set.size();
            set.add(pos);
            afterSize = set.size();
            pos = pos.next;
            if(beforeSize == afterSize){
                return true;
            }
        }
        return false;
    }
}
```