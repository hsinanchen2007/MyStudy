### 解题思路
(2 -> 4 -> 3) + (5 -> 6 -> 4)

设sum = 0表示每一位的和，carry = 0表示进位标志，进位为1，不进位为0
个位：2 + 5 = 7 ==> sum + carry = 7, 不进位, carry = 0
十位：4 + 6 = 10 ==> sum + carry = 0, 进位, carry = 1
百位：3 + 4 = 7 ==> sum + carry = 8, 不进位, carry = 0


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
    let res = new ListNode, sum = 0, carry = 0
    let temp = res
    while(l1 || l2){
        let num1 = l1 ? l1.val : 0
        let num2 = l2 ? l2.val : 0
        sum = num1 + num2 + carry
        temp.next = new ListNode(sum % 10) //当前节点的下一个节点，应该是val为sum取余后的值
        temp = temp.next
        carry = parseInt(sum / 10)
        if(l1){l1 = l1.next}
        if(l2){l2 = l2.next}
    }
    if(carry > 0){temp.next = new ListNode(carry)}  // 特殊情况是(4) + (6)，结果应该是 0 -> 1
    //console.log(res.next)
    return res.next
};
```