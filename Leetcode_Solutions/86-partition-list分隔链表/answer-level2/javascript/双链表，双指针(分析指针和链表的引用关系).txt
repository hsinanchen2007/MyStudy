### 解题思路
- 我觉得这道题理解指针和链表之间的引用关系非常重要
- 参考了大神的代码之后有个疑问就是这里只是修改指针的next节点，为什么链表也会被修改
- ``` smallPoint.next = cur //smallPoint指向before，实际等于before.next = cur ```
- ``` smallPoint = smallPoint.next //smallPoint的指向改变了，指向了before的next, 这时before的next和 smallPoint指向同一对象。 ```

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
 * @param {number} x
 * @return {ListNode}
 */
var partition = function (head, x) {
    const listNode = new ListNode(0)
    listNode.next = head
    let before = new ListNode(0)
    let after = new ListNode(0)
    let smallPoint = before
    let bigPoint = after
    let cur = listNode.next
    while (cur) {
        if (cur.val >= x) {
            bigPoint.next = cur
            bigPoint = bigPoint.next
        } else {
            smallPoint.next = cur
            smallPoint = smallPoint.next
        }
        cur = cur.next
    }
    bigPoint.next = null
    smallPoint.next = after.next
    return before.next
};
```