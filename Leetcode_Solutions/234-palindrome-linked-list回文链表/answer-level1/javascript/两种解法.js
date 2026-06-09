### 解题思路

### 代码
* 快慢指针查找中间值，利用前插方法将前半部分反转，同后半部分进行比较，注意节点奇数情况时，中间值不参与比较
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    if (head === null || head.next === null) return true
    let mid = head, fast = head, reverse = null
    while(fast && fast.next) {
        pre = mid
        fast = fast.next.next
        mid = mid.next
        pre.next = reverse
        reverse = pre
    }
<!-- 奇数个节点时、向后移一位 -->
    fast && (mid = mid.next)
    while(mid) {
<!--  -->
        if (reverse.val !== mid.val) return false
        reverse = reverse.next
        mid = mid.next
    }
    return true
};
```
* 第二种解法。
* 递归，递归的过程即是入栈的过程，得出解的过程即是出栈的过程

```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let p1 = head
    function help(tail) {
<!-- 递归出口 -->
        if(tail !== null) {
<!-- 每个对称节点判断结果，若不相等，则出栈，直至栈的第一层即初始传入head那一层，将结果返回给isPalindrome -->
            if (!help(tail.next)) return false
            if (p1.val !== tail.val) {
                return false
            } 
            p1 = p1.next
        }
        return true
        
    }
    return help(head)
};
```