使用递归的方法
```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    if(l1===null){
        return l2;
    }
    if(l2===null) {
        return l1;
    }
    l1.val = l1.val + l2.val;//对应节点值相加，并赋值给l1的当前节点
    if(l1.val>9) {
        l1.val-=10;
        if(l1.next!=null && l2.next!=null){
            l1.next.val++;
        }
        else if(l1.next===null){
            l1.next = new ListNode(1);//如果链表l1下一个节点为空，则新建一个值为1的新节点补齐
        }
        else if(l2.next===null){
            l2.next = new ListNode(1);//如果链表l2下一个节点为空，则新建一个值为1的新节点补齐
        }  
    }
    l1.next = addTwoNumbers(l1.next,l2.next);//递归
    return l1;
}
```
