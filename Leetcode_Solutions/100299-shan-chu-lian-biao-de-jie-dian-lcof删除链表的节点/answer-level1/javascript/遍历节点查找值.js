### 解题思路
设置当前节点为cNode,前一个节点为pre;
特殊情况：head即为值；
初始化当前节点为head.next；
遍历节点：pre=cNode; cNode=cNode.next; 
删除节点：pre.next=cNode.next;

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {
    if(head.val==val) return head.next;
    let cNode=head.next;
    let pre=head;
    while(cNode!=null && cNode.val!=val){
        pre=cNode;
        cNode=cNode.next;  
    }
    pre.next=cNode.next;
    return head;
};
```