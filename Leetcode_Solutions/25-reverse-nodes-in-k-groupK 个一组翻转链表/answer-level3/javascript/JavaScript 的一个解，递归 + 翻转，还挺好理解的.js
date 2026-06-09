### 解题思路
首先判断当前链表长度还有没有 k 那么长，顺便得到了「剩余链表」的 head

然后就顺理成章地递归了，整个 reverseKGroup 的功能就是「返回输入链表 reverse 前 k 项的结果」

正好 reverse 的过程是个可以 concat 剩余链表的过程，也就是下面 `let P0 = reverseKGroup(Prest, k)`，也就是翻转链表（206）那道题：https://leetcode-cn.com/problems/reverse-linked-list/

### 代码

```javascript
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
var reverseKGroup = function(head, k) {
    let len = 0
    let Prest = head
    while (len < k) {
        if (Prest === null) return head
        Prest = Prest.next
        len += 1
    }
    let P0 = reverseKGroup(Prest, k)
    let P1 = head
    while (len > 0) {
        const temp = P1.next
        P1.next = P0
        P0 = P1
        P1 = temp
        len -= 1
    }
    return P0
}
```