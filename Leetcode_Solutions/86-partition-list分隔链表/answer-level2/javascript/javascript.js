```
var partition = function(head, x) {
    const small = new ListNode();
    let smallNode = small;
    while(head && head.val < x) {
        smallNode.next = new ListNode(head.val);
        smallNode = smallNode.next;
        head = head.next;
    }
    let childNode = head;
    while(childNode &&childNode.next) {
        if(childNode.next.val < x) {
            smallNode.next = new ListNode(childNode.next.val);
            childNode.next = childNode.next.next;
            smallNode = smallNode.next;
        }
        else childNode = childNode.next;
    }
    smallNode.next = head;
    return small.next;
};
```
