## 分析
![](https://pic.leetcode-cn.com/64de7ab567746f90d1137b7a5ffcce1edceac21d12185cd6ee9f57835bf92c1e.png)

## 代码
```java
public ListNode swapPairs(ListNode head) {
        while (head == null || head.next == null) {
            return head;
        }
        ListNode node = new ListNode(-1);
        ListNode res = node;
        while (head != null && head.next != null) {
            node.next = head.next;
            head.next = head.next.next;
            node.next.next = head;

            node = node.next.next;
            head = head.next;

        }
        return res.next;
    }
```
## 递归解法
```java
public ListNode swapPairs(ListNode head) {
        while (head == null || head.next == null) {
            return head;
        }
        ListNode node = head.next;
        head.next = swapPairs(node.next);
        node.next = head;
        return node;
    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)
