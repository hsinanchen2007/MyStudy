```javascript
var deleteNode = function(node) {
    let tmp = node.next.val
    node.next = node.next.next
    node.val = tmp
};