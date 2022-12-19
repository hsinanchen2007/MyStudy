### 解题思路
1. 定义两个指针，指针p每次走一步，指针q每次走两步；
2. 当指针q到达链表尾部时，指针p差不到到达链表中间；
3. 注意尾部边界的处理即可确定链表中间节点。

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
var middleNode = function(head) {
    let p = head,
        q = head;
    
    while (q.next != null && q.next.next != null) {
        p = p.next;
        q = q.next.next;
    }

    if (q.next == null) {
        return p;
    } else {
        return p.next;
    }    

};
```