### 解题思路
使用双指针解法，左指针指向最新确定可以保存的节点，右指针向前寻找下一可保存节点。

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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        int current = 0;
        //头节点可能出现重复需要删除，设置一个新的头节点
        ListNode newHead = new ListNode(0);
        newHead.next = head;
        ListNode first = newHead;
        ListNode second = head;
        while (second.next != null){
            current = second.val;
            //节点val相同处理
            if (current == second.next.val) {
                second = second.next;
                //循环找到下一个可保存节点
                while (second.next != null){
                    if (second.next.val == current) {
                        second = second.next;
                    }else break;
                }
                second = second.next;
                first.next = second;
                if (second == null) break;
            }else {
                first = second;
                second = second.next;
            }
            
        }
        return newHead.next;
        
    }
}
```