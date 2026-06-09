![image.png](https://pic.leetcode-cn.com/8f76cc0b6065b64518348e7e41de3d8e3675e9dd27648b0c6865852a7a807968-image.png)

主要思路就是利用快慢指针，快慢指针每次都指向连续的奇节点，只需要将快指针指向的节点移动到慢指针的下一个节点就可以了。
移动节点之后，快指针的相对位置就应该是preFast指针的位置。大家可以根据代码，结合画图理解一下。
```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode pre = new ListNode(-1);
        pre.next = head;

        // 初始化快慢指针位置，preFast指针方便节点交换，指向fast指针的前一个节点
        ListNode slow = pre;
        ListNode fast = pre.next;
        ListNode preFast = pre.next;
        while (fast.next != null && fast.next.next != null) {
            // 移动指针
            slow = slow.next;
            preFast = fast.next;
            fast = fast.next.next;

            // 交换节点位置
            preFast.next = fast.next;
            fast.next = slow.next;
            slow.next = fast;
            fast = preFast;
        }

        return pre.next;
    }
}
```
