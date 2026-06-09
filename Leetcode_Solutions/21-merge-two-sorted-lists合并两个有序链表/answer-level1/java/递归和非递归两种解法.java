
## 解析
首先判断 l1 或 l2 中是否有一个节点为空，如果存在，那么我们只需要把不为空的节点接到链表后面即可。
本题的思路还是很清晰的，因为l1和l2都是有序的。
新建一个链表res用来存储最后的结果。
因此每次比较l1和l2的头节点的大小。将较小的加入res，并将res和较小的节点所在链表都后移一位。
最后还需要分别判断l1和l2是否已经遍历完。如果有没有遍历完的，直接将其加入res即可。
## 非递归解法代码
```java
public ListNode mergeTwoLists1(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        ListNode tmp = new ListNode(0);
        ListNode res = tmp;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                tmp.next = l1;
                l1 = l1.next;
            } else {
                tmp.next = l2;
                l2 = l2.next;

            }
            tmp = tmp.next;
        }
        if (l1 != null) {
            tmp.next = l1;

        }

        if (l2 != null) {
            tmp.next = l2;

        }

        return res.next;
    }
```

## 递归解法代码

```java
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //递归的第一步：终止条件，l1 == null,则返回l2. l2 == null,则返回l1
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        if (l1.val < l2.val) {
            //如果 l1 的 val 值更小，则将 l1.next 与排序好的链表头相接
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            //如果 l2 的 val 值更小，则将 l2.next 与排序好的链表头相接
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
```
**更多leetcodeleetcode题解可扫描下方二维码关注公众号**
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)