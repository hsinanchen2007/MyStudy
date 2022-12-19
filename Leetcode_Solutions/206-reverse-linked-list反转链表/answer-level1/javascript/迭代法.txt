### 解题思路

pre / cur / post 

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
var reverseList = function(head) {
    // 特殊情况处理
    if (!head || !head.next) {
        return head;
    }

    const reverse = (head) => {
        // 返回值不能是 null，内部约定
        if (head.next == null) {
            return head;
        }

        const tempNext = head.next;

        const reversedHead = reverse(head.next);

        // 尾部添加 head
        tempNext.next = head;
        head.next = null;

        return reversedHead;
    };


    return reverse(head);
};
```