![image.png](https://pic.leetcode-cn.com/2456e32ba744aca1826b115bea4331332a168603f1e00b99cf1fe765a54acefb-image.png)

# 解题思路：
1. 先求出链表的长度len
2. 声明一个零时变量tmp和一个计数变量 i = 1
3. 再次while循环，当i和tmp相等的时候，返回结果

```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function (head, k) {

    let len = 1, cur = head
    while (cur.next != null) {
        cur = cur.next
        len++
    }
    if (k >= len) return head
    let tmp = len - k, i = 1
    cur = head
    while (cur.next != null) {
        cur = cur.next
        if (i++ === tmp) {
            return cur
        }
    }
};
```


