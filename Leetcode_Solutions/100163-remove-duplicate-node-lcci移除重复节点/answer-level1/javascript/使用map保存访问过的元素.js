```javascript []
var removeDuplicateNodes = function(head) {
    if(head === null || head.next === null){
        return head;
    }
    let currentHead = head
    let map = new Map()
    map.set(currentHead.val, true)
    while(currentHead.next !== null){
        let next = currentHead.next;
        if(map.has(next.val)){
            currentHead.next = next.next
        }else{
            map.set(next.val, true)
            currentHead = currentHead.next
        }
    }
    return head;
};
```
