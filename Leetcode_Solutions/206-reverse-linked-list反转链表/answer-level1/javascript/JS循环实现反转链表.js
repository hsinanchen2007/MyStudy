### 解题思路
此处撰写解题思路
用循环实现，存储一个临时中间变量，先把next存储起来，然后交换数据。
### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = 1;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    var returnHead = null;
    var prevHead = head;
    while(prevHead) {
        var tmp = prevHead.next;
        prevHead.next = returnHead;
        returnHead = prevHead;
        prevHead = tmp;
    }
    return returnHead;
};
```