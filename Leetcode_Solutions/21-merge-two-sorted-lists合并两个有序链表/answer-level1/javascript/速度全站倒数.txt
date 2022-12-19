### 解题思路
没用递归，为啥这么慢。
![image.png](https://pic.leetcode-cn.com/a17ee7adb62e72b7700c42efff768fae0ac288669d3eee0470287647f4bcde92-image.png)


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
var mergeTwoLists = function(l1, l2) {
    let head = new ListNode(),
        ret = head;

    while (l1 && l2) {
        if (l1.val < l2.val) {
            head.next = new ListNode(l1.val);
            l1 = l1.next;
        } else {
            head.next = new ListNode(l2.val);
            l2 = l2.next;
        }
        head = head.next;
    }
    while (l1 || l2) {
        if (l1) {
            head.next = new ListNode(l1.val);
            l1 = l1.next;
        } else if (l2) {
            head.next = new ListNode(l2.val);
            l2 = l2.next;
        }
        head = head.next;
    }

    return ret.next;
};
```