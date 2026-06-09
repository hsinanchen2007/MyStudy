
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
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {
    if(!head) return null
    let vHead = new ListNode();
    vHead.next = head;
    let curNode = vHead;
    while(curNode.next){
        if(curNode.next.val === val){
           curNode.next = curNode.next.next;
           return vHead.next;
        }       
        curNode = curNode.next;
    }
};

```