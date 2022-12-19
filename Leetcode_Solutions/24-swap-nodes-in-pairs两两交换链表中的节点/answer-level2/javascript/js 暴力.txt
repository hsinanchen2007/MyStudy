```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    let nodes = [];
    if(!head)
        return null;
    while(head){
        nodes.push(head);
        head = head.next;
    }
    for(let i = 0; i < nodes.length; i = i + 2){
        if(i + 1 < nodes.length){
            let temp = nodes[i];
            nodes[i] = nodes[i + 1];
            nodes[i + 1] = temp;
        }
    }
    nodes.forEach((item,index) => {
        if(index === nodes.length - 1)
            item.next = null;
        else
            item.next = nodes[index + 1];
    })
    if(nodes.length === 0)
        return null;
    return nodes[0];
};
```