### 解题思路
此处撰写解题思路

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
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function (headA, headB) {
    // 定义两个指正，交叉走
    // 如果没有交叉，最后一个正好是null。有交叉返回任意一个最后节点即可
    let p = headA,
        q = headB;
    while (p != q) {
        if (p) p = p.next;
        else p = headB;

        if (q) q = q.next;
        else q = headA;
    }
    return q;
};
```