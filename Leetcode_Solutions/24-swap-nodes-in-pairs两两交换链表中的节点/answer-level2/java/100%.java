写了好长时间，真够饶的。以下是我画的图，哈哈哈，有点乱。
首先：
    1、先将pre和two连接起来
    2、然后将one和after连接起来
    3、最后将two和one连接起来
    4、调整节点：
        最后绕的地方就在这里
        注意判断空值
![image.png](https://pic.leetcode-cn.com/1becf800191e8ef3c95ee28ed2fb9e131495e6bdffcf64bb26f8f31021d858c0-image.png)
```
public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode h = new ListNode(0);
        ListNode t = h;
        h.next = head;

        while (head.next != null){
            ListNode pre = t;
            ListNode one = head;
            ListNode two = head.next;
            ListNode after = two.next;

            pre.next = two;
            one.next = after;
            two.next = one;

            t = one;
            if (head == null || head.next == null) break;
            head = head.next;
        }
        return h.next;
    }
```
