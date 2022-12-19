### 解题思路
用快慢指针，
- 当快指针的值与慢指针的值相等时，右移快指针
- 当快指针的值与慢指针的值不等时，令慢指针的 next 指向快指针，右移双指针
- 当快指针到达链表末尾时，结束

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
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if (!head || !head.next) return head;
    const dump = new ListNode('s');
    dump.next = head;
    let prev = head, current = prev.next;
    while (current && current.next) {
        while (current && current.val === prev.val) {
            current = current.next;
        }
        prev.next = current;
        if (current) {
            prev = prev.next;
            current = prev.next;
        }
    }
    if (current && current.val === prev.val) {
        prev.next = null;
    }
    return dump.next;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(!)