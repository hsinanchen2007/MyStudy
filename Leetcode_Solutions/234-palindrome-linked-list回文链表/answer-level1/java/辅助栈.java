### 解题思路
辅助栈 
注意区分链表个数为奇数还是偶数

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
    public boolean isPalindrome(ListNode head) {
        //bad-case
        if (head == null) {
            return true;
        }

        //bad-case
        if (head.next == null) {
            return true;
        }

        //构建栈
        Deque<ListNode> stack = new LinkedList();

        //快慢指针找中间节点
        ListNode slow = head;//慢指针
        ListNode fast = head;//快指针

        //装入栈
        stack.addFirst(slow);

        //循环找中间节点
        while (fast != null) {
            if (fast.next == null){//奇数
                //出栈
                stack.removeFirst();
                slow = slow.next;
                break;
            } else if (fast.next.next == null) {//偶数
                slow = slow.next;
                break;
            } 
            //走两步
            fast = fast.next.next;
            //走一步
            slow = slow.next;
            //装入栈
            stack.addFirst(slow);
        }

        //判断是否是回文串
        while (!stack.isEmpty()) {  
            //debug
            //System.out.println(slow.val);
            ListNode node = stack.removeFirst();
            //debug
            //System.out.println(node.val);
            if (slow.val != node.val) {
                return false;
            }
            slow = slow.next;
        }

        return true;
    }
}
```