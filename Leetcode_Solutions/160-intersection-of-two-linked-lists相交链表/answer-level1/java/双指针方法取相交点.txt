### 解题思路
详见代码注释

### 代码

```java
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
        //双指针方法
        //特判情况
        if (headA == null || headB ==null) {
            return null;
        }
        //初始化 A和B的头指针
        ListNode pA = headA;
        ListNode pB = headB;
        //判定条件 如果pA 和pB相等 表示相遇（类似于从后向前遍历的方法 但是单向链表无法返回）
        while (pA != pB) {
            //如果不满足 就向后移动
            pA = pA.next;
            pB = pB.next;
            if (pA == null && pB == null) {
                return null;
            }
            //A和B到了末尾之后，继续遍历其他的链表（总长度 A+B）
            if (pA == null){
                pA = headB;
            }
            if (pB ==null) {
                pB = headA;
            }

        }
        //如果相遇 pA和pB 相等
        return pA;
    }
}
```