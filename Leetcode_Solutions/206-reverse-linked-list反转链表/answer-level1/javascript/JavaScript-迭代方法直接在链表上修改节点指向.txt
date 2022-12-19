### 解题思路
直接在链表上修改next指向，完成链表的反转。利用一次遍历，每次遍历，保存current节点（当前节点）的next节点（下个节点），然后改变current节点的next属性指向pre节点（上一个节点），pre节点是每次处理完current节点，要将current节点指向next节点之前，用pre变量保存current节点，作为下一轮循环的pre节点（上一个节点）。

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
    let current = head, pre = null, next = null;
    while(current){
        next = current.next;
        current.next = pre;
        pre = current;
        current = next;
    }
    return pre
};
```