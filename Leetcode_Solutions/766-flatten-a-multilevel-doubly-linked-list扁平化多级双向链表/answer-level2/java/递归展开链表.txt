- 题意为展开链表，规则为：记当前结点为 `cur`，当前结点的下一个结点为 `next`，如果当前结点存在子链表（`child != null` ），需要把子链表展开，并把展开后的子链表链接到 `cur` 与 `next` 之间。因为子链表可能有一个或多个自己的子项，显然展开过程是一个递归过程。
- 保证展开后的链表的每个结点的 `prev`、`next`、`child` 这三个指针的指向是正确的。
  - `prev` 指向上一个结点（如果当前结点为头结点，`prev` 指向 `null`）。
  - `next` 指向下一个结点（如果当前结点为尾结点，`next` 指向 `null`）。 
  - `child` 指向 `null`（链表已经展开了）。
- 在链接  `cur` 、`next` 、子链表三者时，需要用到子链表的头结点和尾结点。可以让展开方法的返回值为展开后链表的头结点，并且让头结点的 `prev` 指向尾结点（头结点的 `prev` 原本指向 `null`，进行废物利用），这样就可以通过一个返回值得到头结点和尾结点两个信息，最后进行还原即可。
- 每个结点只会访问一次，时间复杂度为 `O(n)`，空间复杂度主要源于递归调用，即这个多级链表的最大层数。

```java
class Solution {
    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }
        dfs(head);
        head.prev = null;
        return head;
    }

    /**
     * 展开链表，展开后链表的头结点的 prev 指向尾结点
     *
     * @param head 头结点
     * @return 展开后链表的头结点
     */
    private Node dfs(Node head) {
        Node cur = head;
        while (cur != null) {
            head.prev = cur;    // 更改头结点的 prev 指向尾结点
            Node next = cur.next;
            if (cur.child != null) {
                Node h = dfs(cur.child);
                cur.child = null;
                Node t = h.prev;
                // 链接 cur、h、t、next
                cur.next = h;
                h.prev = cur;
                t.next = next;
                if (next != null) {
                    next.prev = t;
                }
                head.prev = t;  // 更改头结点的 prev 指向尾结点
            }
            cur = next;
        }
        return head;
    }
}
```

更多题解欢迎关注 [https://github.com/Jerring/LeetCode](https://github.com/Jerring/LeetCode) ^_^

