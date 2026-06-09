### 解题思路

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
    if(head == null){
        return head;
    }
    var curent = head;
    var pre = null;
    while(curent){
        var next = curent.next;
        curent.next = pre;
        pre = curent;
        curent = next;
    }
    return pre;
};

```