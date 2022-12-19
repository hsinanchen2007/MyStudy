### 解题思路
有点粗暴。将链表的每一项迭代进行相加。最终返回一个新的链表结构。
判断那边有点啰嗦感觉，还需要优化。r

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
// JavaScript中没有链表，并不是用数组模拟的，只是类数组对象
var addTwoNumbers = function(l1, l2) {
    var en = 0;
    var result = {};
    function noop(result,l1, l2) {
        result.val = l1.val + l2.val + en;
        result.val>9 ? (en =1, result.val-=10):(en =0);
        // if (result.val>9) {
        //     en = 1;
        //     result.val -= 10;
        // }
        // else {
        //     en = 0;
        // }

        if (l1.next && l2.next) {
            noop(result.next = {}, l1.next, l2.next)
        }
        else if(l1.next) {
            noop(result.next = {}, l1.next, {val: 0, next: null})
        }
        else if(l2.next) {
            noop(result.next = {}, {val: 0, next: null}, l2.next)
        }
        else if(en > 0) {
            result.next = {
            val: en,
            next: null
            }
            en =0;
        }
        else {
            result.next = null
        }
        return result;
    }
    return noop(result, l1, l2);

};
```