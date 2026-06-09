```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let result = new ListNode(null);
    let nextRst = result;
    // 进位
    let params = 0 // 传给下一个层级的值
    let val = 0 // 传给当前层级的值
    
    while(l1 != null || l2 != null) {
        // TODO
        let x = (l1 != null) ? l1.val : 0;
        let y = (l2 != null) ? l2.val : 0;
        
        val = (x + y + params) % 10;
        params = Math.floor((x + y + params) / 10);
       
        nextRst.next = new ListNode(val) 
        nextRst = nextRst.next
        
        if(l1 != null) l1 = l1.next
        if(l2 != null) l2 = l2.next        
    
    }
    
    if(params) {
       nextRst.next = new ListNode(params)
    }
    
    return result.next
};
```