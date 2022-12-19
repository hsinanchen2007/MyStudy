- ![clipboard1.png](https://pic.leetcode-cn.com/ed34430e84a1636322a3f15d460488324385baae55983c97a173c564ec7710eb-clipboard1.png)

```
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (k == 0 || head == null || head.next == null) {
            return head;
        }

        ListNode tail = head;
        int length = 1;
        while (tail.next != null) {
            tail = tail.next;
            length ++;
        }

        int backStep = k % length;
        // 后退步数和链表长度一样，等于没变动
        if (backStep == length) {
            return head;
        }

        // 构造环
        tail.next = head;

        // 后退步数转前进步数，找新链表的尾巴
        int forwordStep = length - backStep;
        for (int i = 0; i < forwordStep; i ++) {
            tail = tail.next;
        }

        // 将环切断转链表
        head = tail.next;
        tail.next = null;

        return head;
    }
}
```
