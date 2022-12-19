
两个链表的每个节点全部入栈，然后同时出栈，第一个相同的节点就是要求的结果。

``` js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let stackA = [];
    let stackB = [];
    let curA = headA;
    let curB = headB;
    //有两个神仙样例。。。
    if(curA == null||curB == null) return null;
    if(curA == curB) return curA;
    while(curA){
        stackA.push(curA);
        curA = curA.next;
    }
    while(curB){
        stackB.push(curB);
        curB = curB.next;
    }
    //同时出栈,定义一个变量保存最后结果
    let res = null;
    while(true){
        let a = stackA.pop();
        let b = stackB.pop();
        if(a!=b){
            return res;
        }else res = a;
    }
};
```