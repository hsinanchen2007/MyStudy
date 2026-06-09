# 两数之和

思路

- 在计算链表元素之和时，要考虑进位和实际存入链表的值
- 新建链表要有2个指针，一个记录初始位置，一个记录当前位置
- 若进位值最后为1，要在当前链表指针添加新的结点

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
const addTwoNumbers = function(l1, l2) {
    let carry = 0, sum, head , pre;
    head = pre = new ListNode(0);
    while(l1 || l2 ){
        // 元素求和，考虑进位
        sum = (l1 && l1.val) + (l2 && l2.val) + carry;
        // 进位值更新
        carry = Math.floor(sum / 10);
        head.next = new ListNode(sum % 10);
        // 指针更新
        head = head.next;
        l1 = l1 && l1.next;
        l2 = l2 && l2.next; 
    }
    if(carry == 1){
        head.next = new ListNode(carry);
    }
    return pre.next;
};

```