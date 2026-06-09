### 解题思路
直接看注释吧

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
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if(!head || !head.next)return head; //避坑
    const link = head.next;
    let node=head, edge=null;
    while(node && node.next){
        const thisOne = node;
        const nextOne = node.next; //获取当前节点和它的下一节点
        const afterNext = nextOne.next; //获取下下一个节点
        nextOne.next = thisOne; 
        thisOne.next = afterNext; //调换俩个节点的位置
        if(edge){
            edge.next = nextOne; //如果有前一个节点，修改前一个节点的next指向
        }
        edge = thisOne;
        node = afterNext;
    }
    return link;
};
```