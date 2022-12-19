### 解题思路
此题目的关键盲区在于不知道ListNode到底是个啥，如何赋值，以及如何返回。
1.listnode是一个链表结构，拥有next方法，返回指针指向下一个元素，
2.val方法用来返回当前指针指向元素的val值。
3.通过node = node.next赋值来递归listnode中的所有元素。
4.返回值的关键思路是定义一个新的变量l3，与node指向同一个位置。
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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let b = null;
    let i = 0;
    let arr = [];
    let l3;
    let pre = 0;

    while(l1 || l2) {
        l1 = l1 ? l1 : new ListNode(0);
        l2 = l2 ? l2 : new ListNode(0);
        let tmp = l1.val + l2.val + pre;
        if (!b) {
            b = new ListNode(tmp % 10);
            l3 = b;
        } else {
            b.next = new ListNode(tmp % 10);
            b = b.next;
        } 
        tmp - 10 >= 0 ? pre = 1 : pre = 0;

        l1 = l1.next;
        l2 = l2.next;
    }
    
    if (pre) {
        b.next = new ListNode( pre % 10);
        b = b.next;
    }
    return l3;
};
```