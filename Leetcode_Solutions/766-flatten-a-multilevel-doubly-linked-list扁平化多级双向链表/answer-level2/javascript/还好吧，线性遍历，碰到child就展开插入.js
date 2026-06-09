```
/**
 * // Definition for a Node.
 * function Node(val,prev,next,child) {
 *    this.val = val;
 *    this.prev = prev;
 *    this.next = next;
 *    this.child = child;
 * };
 */
/**
 * @param {Node} head
 * @return {Node}
 */
var flatten = function(head) {
    let cur = head
    while(cur) {
        if(cur.child) {
            const [n1, n2] = get_child(cur.child)
            cur.child = null
            let temp = cur.next
            cur.next = n1
            n1.prev = cur
            n2.next = temp
            if(temp) temp.prev = n2
        }
        cur = cur.next
    }
    return head
};

function get_child(node){
    let cur = node
    while(cur.next) cur = cur.next
    return [node, cur]
}
```
