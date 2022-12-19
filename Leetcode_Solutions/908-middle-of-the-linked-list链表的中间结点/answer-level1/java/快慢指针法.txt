### 解题思路
构造快慢指针，快指针一次走两步，慢指针一次走一步。当***fast==null || fast.next==null***时，说明快指针已走完！
此处在慢指针处查找找中间节点

> 注意单数和偶数的区别！

##### 单数列表
例如[1,2,3],走一步后，fast.next == null, slow=2 ，刚好是中间节点
##### 双数列表
例如[1,2,3,4],走两步时，fast == null ，slow = 3 ,刚好为两中间节点的第二个点
##### 综上所得
当***fast==null || fast.next==null***时，slow为中间节点

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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(true){
             if(fast == null || fast.next == null){
                return slow;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
    }
}
```