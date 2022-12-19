### 解题思路
从个位开始加，有进位cf就等于1，加到后面一位的结果里。 最后只有l1,l2,cf都为null或0时停止计算。

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
    let res = new ListNode(null)
    let headPointer = res
    let cf = 0 // 进位
    let sum = 0

    while(l1 || l2 || cf){    
        sum = (l1?l1.val:0) + (l2?l2.val:0) + cf
        cf = sum>9?1:0 
        res.next = new ListNode(sum%10)
        res = res.next
        l1 = l1?l1.next:null
        l2 = l2?l2.next:null

    }

    return headPointer.next


};
```