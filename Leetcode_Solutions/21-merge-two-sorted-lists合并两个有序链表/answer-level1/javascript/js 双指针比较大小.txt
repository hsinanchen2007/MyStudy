```
var mergeTwoLists = function(l1, l2) {
    let head = null, current = null;
    while(l1 || l2){
        let currentNode = null;
        if(!l1){
            currentNode = l2;
            l2 = l2.next;
        }else if(!l2){
            currentNode = l1;
            l1 = l1.next;
        }else {
            if(l1.val > l2.val){
                currentNode = l2;
                l2 = l2.next;
            }else{
                currentNode = l1;
                l1 = l1.next;
            }
        }
        if(head === null){
            head = currentNode;
            current = head;
            current.next = null;
        }else{
            currentNode.next = null;
            current.next = currentNode;
            current = current.next;
        }
    }
    return head;
};
```