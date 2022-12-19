### 重复题 原题是leetcode 2 两数相加 
在字节飞书的笔试题写过
```js
var addTwoNumbers = function(l1, l2) {
    let sum = 0,
        head = {},
        cur = head;
    while(l1 || l2 || sum) {
        sum += (l1 && l1.val) + (l2 && l2.val);
        cur = cur.next = new ListNode(sum % 10);
        l1 = l1 && l1.next;
        l2 = l2 && l2.next;
        sum = Math.floor(sum / 10);
    }
    return head.next;
};
```