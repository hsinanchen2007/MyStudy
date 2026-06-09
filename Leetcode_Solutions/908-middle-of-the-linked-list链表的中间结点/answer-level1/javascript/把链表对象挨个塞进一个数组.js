### 解题思路
就这样。。。
![image.png](https://pic.leetcode-cn.com/6c6ba34f3ef0c58f84c2062d4a0a4ea882130bfa0f2fa5ae19be9d41e1fb01ae-image.png)


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
var middleNode = function (head) {
    if(!head) return null;

    let nodeArr = [];

    while (head) {
        nodeArr.push(head);
        head = head.next;
    }
    return nodeArr[Math.floor(nodeArr.length / 2)];
};
```