### 解题思路
这道题用哈希表做，我用到set.contains()方法[判断set集合中是否有指定的元素]。
遍历数组，如果head为空则不构成循环链表，直接退出返回false,如果head在set集合中存在则构成循环链表。
eg:[3,-2,0,4] 1     set集合中放入的是[3，-2，0，4],一遍遍历完成，head=head.next=-2,-2在set集合中则构成循环链表。返回true。

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
        Set<ListNode> set = new HashSet<>();
        while(head != null){
            if(set.contains(head)){
                return true;
            }else{
                set.add(head);
            }
            head = head.next;
        }
        return false;
    }
}
```