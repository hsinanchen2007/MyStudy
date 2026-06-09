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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let result = new ListNode(0)
    let tmp = result // tmp类似指针，引用类型
    let shang = 0; // 商
    while (l1 !== null || l2 !== null) { // 当l1, l2不为null都要进行循环
        const l1Val = l1 === null ? 0 : l1.val; // 取值，为null时当做0处理，为了处理位数不一样的情况
        const l2Val = l2 === null ? 0 : l2.val; // 同理
        const sum = l1Val + l2Val + shang; // 求和，加上上次计算的商
        let remainder = sum % 10; // 余数为本位的值
        shang = Math.floor(sum / 10); 
        tmp.next = new ListNode(remainder); // tmp作为变量，负责变更指针位置，next
        tmp = tmp.next;
        if (l1 !== null) l1 = l1.next // 往下继续循环
        if (l2 !== null) l2 = l2.next
    }
    if (shang !== 0) {
        tmp.next = new ListNode(shang)
    }
    return result.next
};
```