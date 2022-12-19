```
var mergeTwoLists = function(l1, l2) {
    if(!l1) {
        return l2
    }
    if(!l2) {
        return l1
    }
    const [beforeNode, afterNode] = l1.val>=l2.val?[l2, l1]:[l1, l2];
    const headNode = new ListNode(beforeNode.val);
    headNode.next = mergeTwoLists(afterNode, beforeNode.next)
    return headNode;
};
```
