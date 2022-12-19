![image.png](https://pic.leetcode-cn.com/caa4e63e702dfe58e290a5587b99519b8d6eb663ca98e1190ec9896e6661ab48-image.png)


### 解题思路

- 定义快慢两个指针，初始都指向 head
- 每次迭代，快指针前进两步，慢指针前进一步
- 如果快慢指针相等，则代码链表存在环

### 复杂度分析

- 时间复杂度：O(n)
- 空间复杂度：O(1)

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
 * @return {boolean}
 */
var hasCycle = function(head) {
    // 快慢指针
    let fast = slow = head
    while (fast && fast.next) {
        fast = fast.next.next
        slow = slow.next
        if (fast === slow) {
            return true
        }
    }
    
    return false
};
```