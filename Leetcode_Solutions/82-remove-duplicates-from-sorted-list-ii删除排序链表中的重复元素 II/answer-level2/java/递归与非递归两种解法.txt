## 分析

新建一个链表res表示最后返回的链表。
用一个bool型变量dup表示是否有重复的节点。如果一个节点的值与其next节点的值相等。表示是重复节点，将dup设置为true。往后顺移，直到不相等为止。
将当前节点加入最后返回的链表res的时候，需要判断一下dup是否为true。如果为true的话，表示当前节点是重复的。举个例子：
2->2->3。 刚开始第一个2和第二个2相等。顺移一位，dup设为true。此时2和3不相等。但是这个2其实不能加到最后的返回结果中。
因此，需要判断一下dup是否为true。如果不为true，才能加到最后的返回结果中。
## 代码
```java
public ListNode deleteDuplicates1(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode res = new ListNode(-1);
        ListNode node = res;
        while (head != null) {
            boolean dup = false;
            while (head != null && head.next != null && head.val == head.next.val) {
                head = head.next;
                dup = true;
            }
            if (!dup) {
                res.next = head;
                res = res.next;

            }
            head = head.next;
        }
        res.next = null;  //防止res后面还有重复的节点
        return node.next;
    }
```
递归版本
```java
public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return head;
        }

        if (head.next != null && head.val == head.next.val) {
            while (head != null && head.next != null && head.val == head.next.val) {
                head = head.next;
            }
            //去掉所有重复的数字，然后进行递归
            return deleteDuplicates(head.next);
        } else {
            head.next = deleteDuplicates(head.next);
        }
        return head;
    }
```
**更多leetcode题解可扫描下方二维码关注公众号**
[![](https://pic.leetcode-cn.com/271220540867376d8820ad08344c43f64257efda6a44cb2f34e55374d8475914)](https://pic.leetcode-cn.com/271220540867376d8820ad08344c43f64257efda6a44cb2f34e55374d8475914)