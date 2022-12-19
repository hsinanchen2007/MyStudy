快指针与慢指针

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
var hasCycle = function(head) {
    if (head == null || head.next == null) {
        return false
    }
    let slow = head
    let fast = head.next
    while (slow != fast) {
        if (fast.next && fast.next.next) {
            slow = slow.next
            fast = fast.next.next
        } else {
            return false
        }
    }
    return true
};
```


哈希map

```
var hasCycle = function(head) {
    const map = new WeakMap()
    while (head) {
        if (map.get(head)) {
            return true
        } else {
            map.set(head, true)
            head = head.next
        }
    }
    return false
};
```