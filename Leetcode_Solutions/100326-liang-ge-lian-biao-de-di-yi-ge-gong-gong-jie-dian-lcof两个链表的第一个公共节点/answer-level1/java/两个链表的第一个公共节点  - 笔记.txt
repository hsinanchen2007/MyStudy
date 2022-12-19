### 解题思路
双指针。
- 获取取两个链表的长度，存储当前指针
- 对较长的链表进行移动处理。比如：A比较长，移动到与B一样长的位置
- 到这步，curA、curB的长度都一样了，这时候可以直接遍历比较
- 

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
        if (headA == null || headB == null) {
            return null;
        }
        // 获取取两个链表的长度
        int lenA = getNodeLength(headA);
        int lenB = getNodeLength(headB);
        // 存储当前指针
        ListNode curA = headA;
        ListNode curB = headB;
        if(lenA > lenB) {
            // A比较长，移动到与B一样长的位置
            for(int i = 0; i < lenA - lenB; i++){
                curA = curA.next;
            }
        } else if (lenB > lenA){
            // B比较长，移动到与A一样长的位置
            for(int i = 0;i < lenB - lenA; i++){
                curB = curB.next;
            }
        }
        // 到这步，curA、curB的长度都一样了，这时候可以直接遍历比较
        while (curA != null) {
            if (curA == curB) {
                return curA;
            }
            curA = curA.next;
            curB = curB.next;
        }
        return null;
    }

    private int getNodeLength(ListNode head) {
        int counter = 0;
        ListNode cur = head;
        while (cur != null) {
            cur = cur.next;
            counter++;
        }
        return counter;
    }
}
```