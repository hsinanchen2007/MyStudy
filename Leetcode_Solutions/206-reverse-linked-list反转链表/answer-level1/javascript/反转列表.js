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
const reverseList = (head)=> {
    if(!head) return head;
    let nodeHead = head;
    let lastFoot = null;
    let foot;

    while(nodeHead){
        foot = new ListNode(nodeHead.val);
        foot.next = lastFoot;
        lastFoot = foot;
        nodeHead = nodeHead.next;
    }

    return foot;
};
```
