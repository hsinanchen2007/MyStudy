### 解题思路
- 删除链表倒数第n个节点就要先找到它的前一个节点
- 将前一个节点的下一个节点指向倒数第n个节点的后一个节点
- 快慢指针，慢指针用来定位要找的前一个节点
- 快指针领先慢指针n+1位，他们同时运动
- 快指针到达末尾null时，慢指针找到删除节点前一个节点

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let dummy = new ListNode(-1)
    dummy.next = head
    let L = dummy, R = dummy, space = n + 1
    while(space){
        R = R.next
        if(space > 1 && R === null) return dummy.next
        space --
    }
    while(R){
        L = L.next
        R = R.next
    }
    L.next = L.next.next
    return dummy.next
};
```