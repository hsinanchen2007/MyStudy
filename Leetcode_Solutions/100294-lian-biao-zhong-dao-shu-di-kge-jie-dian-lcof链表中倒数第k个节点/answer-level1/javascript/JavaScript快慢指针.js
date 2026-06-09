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
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    var last = head;
    var pre = head;
    for(var i = 1; i < k; i++){
        last = last.next;
    }
    while(last.next){
        pre = pre.next;
        last = last.next;
    }
    return pre;
};
```