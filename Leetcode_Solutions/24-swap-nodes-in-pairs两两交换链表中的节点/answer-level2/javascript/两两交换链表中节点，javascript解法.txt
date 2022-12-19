### 解题思路
我的解法是两两一循环，比较麻烦的点在于后一个两两交换完成时，前一个两两交换中第二个节点（也就是原head）的next需要更新。因此引入了新节点pre,作用在于到了下一个两两交换中，仍然可以调用到上一次两两交换的原head。
### 代码
``` javascript
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
    let h
    if (head===null||head.next===null) {
        return head;
    }else{
        h = head.next;
    }
    let pre =  new ListNode(0);
    while(head){
        let nexthead
        if (head.next===null){
            break;
        }else{
            nexthead=head.next.next;
            head.next.next=head;
        }
        let second=head.next;
        head.next=nexthead;
        // pre用来缓存上一个head，因为它需要改正next值
        pre.next=second;
        pre=head;
        head=nexthead;
    }
    return h;
};
```