### 解题思路
用一个头结点保存指针，需要考虑链表长度不等时一方先遍历结束的情况。
时间复杂度：O(n)，空间复杂度：O(1)

执行用时 :92 ms, 在所有 JavaScript 提交中击败了81.00%的用户
内存消耗 :37.7 MB, 在所有 JavaScript 提交中击败了100.00%的用户

### 代码

```javascript
var mergeTwoLists = function (l1, l2) {
    let head = new ListNode();
    let pre = head;
    while (l1 && l2) {
        if (l1.val <= l2.val) {
            let next = l1.next;
            head.next = l1;
            l1 = next;
        } else {
            let next = l2.next;
            head.next = l2;
            l2 = next;
        }
        head = head.next;
    }
    !l1 && (head.next = l2);
    !l2 && (head.next = l1);
    return pre.next
};
```