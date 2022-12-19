![微信图片_20200403192555.png](https://pic.leetcode-cn.com/2233e05f8159043ca1f3d545a4bde4b980ec3615df83880eaf6eb43ee9135903-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200403192555.png)

![微信图片_20200403192602.jpg](https://pic.leetcode-cn.com/92d172a8cbc8c8ebf12e3fb96dcbdc74bcc6fc816d5bca6f570055c93f26ad03-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200403192602.jpg)


```
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {


        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        //新的头节点
        ListNode tempHead = null;
        ListNode tail = null;
        ListNode tailHead = null;
        ListNode cur = dummyHead.next;
        ListNode tempPrev = dummyHead;
        ListNode prev = dummyHead;

        if (head == null || head.next == null) {
            return head;
        }

        if (m == n) {
            return head;
        }

        int idx = 1;


        while (cur != null) {

            if (idx == m) {
                tempHead = cur;

                tempPrev = prev;

            } else if (idx == n) {
                tail = cur;

                tailHead = cur.next;
                break;
            }
            prev = cur;
            cur = cur.next;
            idx++;
        }

        assert tail != null;
        tail.next = null;
        ListNode reverseHead = reverseNode(tempHead);
        assert reverseHead != null;
        tempPrev.next = reverseHead;
        tempHead.next = tailHead;
        return dummyHead.next;


    }
      public static ListNode reverseNode(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHead = reverseNode(head.next);

        head.next.next = head;
        head.next = null;
        return newHead;
    }
}
```
