![逆置单链表.png](https://pic.leetcode-cn.com/e2120e03408d8bf399840a770329d8821705a2e995a2d12439d344f7aca9f535-%E9%80%86%E7%BD%AE%E5%8D%95%E9%93%BE%E8%A1%A8.png)

```
public static int[] reversePrint3(ListNode head) {
        ListNode cur = head;
        ListNode pre = null;

        ListNode newHead = null;

        int cnt = 0;
        while (cur != null) {
            ListNode tmp = cur.next;
            if (tmp == null) {
                newHead = cur; //后面不能加 break，不然 cur 的指向就没有了
            }
            cur.next = pre;
            pre = cur;
            cur = tmp;
            cnt++;
        }
        int[] res = new int[cnt];
        int i = 0;
        while (newHead != null) {
            res[i++] = newHead.val;
            newHead = newHead.next;
        }
        return res;
    }
```

