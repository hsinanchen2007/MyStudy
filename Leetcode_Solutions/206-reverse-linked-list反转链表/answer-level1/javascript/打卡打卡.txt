### 解题思路
此处撰写解题思路
模拟一个栈，将结点依次放入栈中，出栈顺序即为反转后的链表。
### 代码

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if(head == null) {
        return head;
    }
    var L = new ListNode(0);
    L.next = head;
    var arr = [];
    for(let i = head; i != null; i = i.next) {
        arr.push(i);
    }
    var p = L;
    while (p != null) {
        p.next = arr.pop();
        p = p.next;
    }
    return L.next;
};
```