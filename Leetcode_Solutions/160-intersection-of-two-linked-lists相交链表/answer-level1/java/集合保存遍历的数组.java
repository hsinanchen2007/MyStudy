### 解题思路
保存遍历的数组 另一个数组遍历时 判断是否在集合里

### 代码

```java
import java.util.Set;
import java.util.HashSet;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        //Hash存当前的数据
        Set<ListNode>  list  = new HashSet();
        //处理特例
        if (headA == null || headB == null) {
            return null;
        }

        //从headA开始遍历 保存到set集合里
        while (headA != null) {
            list.add(headA);
            headA = headA.next;
        }

        //从HeadB开始遍历
        while (headB != null) {
            if (list.contains(headB)) {
                return headB;
            } 
            headB = headB.next;
        }

        return null;
    }
}
```