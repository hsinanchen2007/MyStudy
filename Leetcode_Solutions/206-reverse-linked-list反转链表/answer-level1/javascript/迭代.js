### 解题思路
将当前节点的next指针改为指向前一个元素。需要另一个指针来存储下一个节点，迭代时将当前节点的next指向前一个元素。

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
    var pre = null;
    var curr = head;
    while(curr!=null)
    {
        var nextTemp = curr.next;
        curr.next = pre;
        pre = curr;
        curr = nextTemp;
    }
    return pre;
};
```