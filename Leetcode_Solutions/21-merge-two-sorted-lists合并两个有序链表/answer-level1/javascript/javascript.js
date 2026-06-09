
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
function ListNode(val) {
      this.val = val;
      this.next = null;
}
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let prev = new ListNode(null);
    let start = prev;
    let l1Current = l1;
    let l2Current = l2;
    
    while(l1Current || l2Current) {
        
        // 比大小, 注意相等的情况 ^_^
        if (l1Current && (!l2Current || l1Current.val <= l2Current.val)) {
            prev.next = new ListNode(l1Current.val);
            prev = prev.next;
            l1Current = l1Current.next;
        }
        if (l2Current && (!l1Current || l2Current.val <= l1Current.val)) {
            prev.next = new ListNode(l2Current.val);
            prev = prev.next;
            l2Current = l2Current.next;
        }
    }
    
    return start.next;
};
```