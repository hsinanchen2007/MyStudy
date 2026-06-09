循环链表，求出链表长度(便于后续求余数，也就是移动次数)，循环过程中节点依次入栈，循环结束，尾节点出栈
让尾节点的next指向头节点，尾节点就变成了第一个结点，此时应该进入栈底。
此时栈中的最后一个结点也就是原始链表中的倒数第二个结点，让其next指向空。
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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    if(head===null||head.next===null)return head;
    let len = 0;//链表长度
    let p = head;
    let first = head;//第一个结点
    let stack = [];//辅助栈
    while(p){
        stack.push(p);
        p = p.next;
        len++;
    }
    p = stack.pop();
    for(let i = 1;i<=k%len;i++){
        p.next = first;
        stack.unshift(p);
        first = p;
        p = stack.pop();
        p.next = null;
    }
    return first;
};
```
