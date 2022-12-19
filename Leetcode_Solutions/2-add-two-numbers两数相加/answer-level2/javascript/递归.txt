```
const addTwoNumbers = function(l1, l2) {
    const resultNode = new ListNode(0)
    let carry = 0
    while(l1 || l2) {
        let currentNode = resultNode
        while(currentNode.next) {
            currentNode = currentNode.next
        }
        let val = carry
        if(l1) {
            val += l1.val
        } 
        if(l2) {
            val += l2.val
        } 
        
        currentNode.val = val % 10
        carry = Math.floor(val / 10)
        l1 = l1 ? l1.next : l1
        l2 = l2 ? l2.next : l2   
        if(l1 || l2 || carry) {
            currentNode.next = new ListNode(carry)
        }
    }
    return resultNode
};
```
