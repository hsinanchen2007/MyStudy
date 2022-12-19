### 解题思路
此处撰写解题思路

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
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    let pre,cur,front
    let p=node=new ListNode()
    p.next=head
    for(let i=1;i<m;i++){
        p=p.next
    }
    front=p//第一刀的左边用front保存起来也是第一段不需要反转的最后一个点
    pre=tail=p.next//那么它的下一个第一刀的右边也就是需要反转的第一个点用tail保存起来，反转之后他将会是第二刀的左边
    cur=pre.next
    for(let i=m;i<n;i++){
        let next=cur.next
        cur.next=pre
        pre=cur
        cur=next
    }
    front.next=pre//重新接上第一刀
    tail.next=cur//重新接上第二刀
    return node.next
};
```
将整个链表分成了3段，第一段不需要反转，第二段需要反转，第3段不需要反转。
那么只需要找准3段中间的分割点，相当于切两刀，一共4个点。再加上一个反转链表就可以实现。