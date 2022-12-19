### 解题思路
![image.png](https://pic.leetcode-cn.com/658d901f277771fb32f1eb413f6e9dbaa0991ccd050858cb8ab235c2a14eb069-image.png)

我再来试下递归。。。

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
var reverseList = function (head) {
    if(!head) return null;

    let nodeArr = [];

    while (head) {
        nodeArr.push(head.val);
        head = head.next;
    }

    let ret = node = new ListNode(nodeArr[nodeArr.length - 1]);

    for (let i = nodeArr.length - 2; i >= 0; i--) {
        node.next = new ListNode(nodeArr[i]);
        node = node.next;
    }

    return ret;
};
```