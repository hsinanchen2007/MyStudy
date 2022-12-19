### 解题思路
- 找到需要删除节点的上一个节点
- 如果找到将上一个节点的next指向下一个节点，来删除当前节点

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
    let c=new ListNode(null);
    c.next=head;
    let r=c;
    while(head){
        if(head.val==val){
            break;
        }
        head=head.next
        c=c.next
    }
    //如果有的话
    if(c.next){
        c.next=c.next.next
    }
    return r.next;
};
```