var deleteNode = function(node) {
    node.value=node.next.value;
    node.next=node.next.next
};