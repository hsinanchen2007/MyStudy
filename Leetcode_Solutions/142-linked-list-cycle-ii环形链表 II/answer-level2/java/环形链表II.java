### 解题思路
1. 题目分两个阶段，均使用两个指针。第一阶段使用快慢指针，找到第一次相遇的点。注意，两指针从head开始。
2. 第二阶段，两个指针一个指向相遇处，一个指向head，速度相同，直到相遇。即为结果。

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
        if(head == null) return null;
        ListNode first = head, second = head;
        while(first != null && second != null){
            first = first.next;
            second = second.next;
            if(second != null) second = second.next;
            else return null;
            if(first == second){
                ListNode res = head;
                while(first != res){
                    first = first.next;
                    res = res.next;
                }
                return res;
            }
        }
        return null;
    }
}
```