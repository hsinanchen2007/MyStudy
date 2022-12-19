### 解题思路

1. 循环遍历，利用数组提供的 ``unshift`` 方法来实现
2. 递归遍历，走到链表最后一个元素时开始 ``push``

### 循环写法

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
 * @return {number[]}
 */
var reversePrint = function(head) {
    let res = []
    while (head) {
        res.unshift(head.val)
        head = head.next
    }
    return res
};
```

### 递归写法

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
 * @return {number[]}
 */
var reversePrint = function(head) {
    const helper = (head) => {
        if (!head) {
            return
        }
        helper(head.next)
        res.push(head.val)
    }
    let res = []
    helper(head)
    return res
};
```