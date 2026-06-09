### 解题思路
首先考虑递归，可以将链表看成一段一段的执行栈，问题就变成了找递归的结束和递归的时机

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
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    //用于进行链表转换
    let pre = null,cur = head;
    let p = head;
    //查找长度是否满足反转的数量
    for(let i = 0;i<k;i++){
        if(p == null) return head;
        p = p.next;
    }
    //对该k个链表元素进行反转
    for(let j = 0;j<k;j++){
        let temp = cur.next;
        cur.next = pre;
        pre = cur;
        cur = temp;
    }
    //反转后。head.next已经成为当前反转后链表的最后一个元素，它的指向将是下一个递归的开始点
    //而此时pre已经是最后一个元素，cur是下一个范围的第一元素
    head.next = reverseKGroup(cur,k);
    return pre;
};
```