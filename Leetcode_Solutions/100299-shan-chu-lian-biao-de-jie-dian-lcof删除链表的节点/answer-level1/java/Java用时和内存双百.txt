### 解题思路

记录两个节点，一个前面，一个后面，后面匹配，前面指向后面的后面
剑指Offer上说是直接删除，但是这个题好像不可以
![图片.png](https://pic.leetcode-cn.com/3124b98a7de14c2e86a0f2c5e86bb0f9de45ca97400a9a6b7814fc34960459fa-%E5%9B%BE%E7%89%87.png)


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
    // 记录两个节点，一个前面，一个后面，后面匹配，前面指向后面的后面
    public ListNode deleteNode(ListNode head, int val) {
        if (head.val == val) {
            if (head.next == null) return null;
            else return head.next;
        }
        ListNode back = head, front = head.next;
        // 如果front不为倒数第一个
        while(front.next != null) {
            if (front.val == val) {
                back.next = front.next;
                return head;
            }
            back = back.next;
            front = front.next;
        }
        back.next = null;
        return head;
    }
}
```