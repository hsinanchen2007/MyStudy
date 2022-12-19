### 解题思路
此处撰写解题思路

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
    if (!head) return null;
    if (!head.next) return head;
    let indicator = head, temp = head.next;
    while (temp) {
      head.next = temp.next;
      temp.next = indicator;
      indicator = temp;
      temp = head.next;
    }
    return indicator;
  };
```