### 解题思路

 * 创建一个数组
 * 遍历链表
 * 保存所有node的引用，返回length / 2的

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
    let list = [head];

    while (head.next) {
        head = head.next;
        list.push(head);
    }
    return list[Math.floor(list.length / 2)];
};
```