### 解题思路
 1.关键点就在进值。
 2.链表完全可以当做数组来看。
 3.基本原理:只要下标相同的值相加有溢出，就存储在第三个值里，留给下一位相加
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
    let result = new ListNode(null),
        pointer = result,
        extend = 0,
        val = 0
// 两个位null则已遍历完成
    while(l1 != null || l2 != null){
        let a = (l1 != null) ? l1.val : 0;
        let b = (l2 != null) ? l2.val : 0;
        // 取余
        val = (a + b + param)%10
        // 取溢出值
        extend = Math.floor((a + b + param)/10)
        pointer.next = new ListNode(val)
        pointer = pointer.next
        if(l1 != null){
            l1 = l1.next
        }
        if(l2 != null){
            l2 = l2.next
        }
    }
    // 如果最后相加还有溢出的话，给它创建一个新节点
    if(extend > 0){
        pointer.next = new ListNode(extend)
    }
    return result.next
};
```