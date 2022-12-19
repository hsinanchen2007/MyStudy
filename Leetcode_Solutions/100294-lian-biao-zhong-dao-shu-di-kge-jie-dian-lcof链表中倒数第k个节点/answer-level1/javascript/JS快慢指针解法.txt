
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
    if(!head || !k || k<=0){
        return null
    }
    let fast = head,
        low = head;
    for(let i=0;i<k-1;i++){
        if(fast.next){
            fast = fast.next;
        }else{
            return null
        }
    }
    while(fast.next){
        fast = fast.next;
        low = low.next;
    }
    return low
};

```