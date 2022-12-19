### 解题思路

这道题的思路就是：

- 提供快慢指针，``prev`` 指向上一个节点，``curr`` 指向当前节点
- 每次都将 ``curr`` 拼接到 ``head`` 上

![反转链表.png](https://pic.leetcode-cn.com/7cdab374aabca619a2a3ae79318c0dcc73417783f554816686423b06f35f081e-%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.png)


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
 * @return {ListNode}
 */
var reverseList = function(head) {
    // 如果为空那么直接返回 null
    if (!head) {
        return null
    }
    // prev 指向上一个节点
    let prev = head
    // curr 指向当前节点
    let curr = head.next
    // 每次将当前节点拼接到 head 之前
    // 最后得到到就是反转后的链表
    while (curr) {
        let temp = head
        let next = curr.next
        prev.next = next
        curr.next = temp
        head = curr
        curr = next
    }
    return head
};
```

- 时间复杂度：$O(n)$
- 空间复杂度：$O(1)$