### 解题思路
1. 起始：**lHead** 为反转后链表的头节点，初始化为空。**node** 指向当前正在操作的节点，初始化为链表头节点。
2. 迭代时，需要一个临时节点来记录当前节点的下一个节点，临时节点我们命名为 **next**。
3. 迭代过程如下：
    3.1 next 保存 node 节点的下一个节点，防止链表丢失。
    3.2 然后修改 node 节点的 next 值为 lHead。
    3.3 修改反转链表的头节点 lHead 为 node。
    3.4 将 node 指向下一个要操作的节点

![反转链表.png](https://pic.leetcode-cn.com/c1286df974109124962e6109d96cec530c7ffb588894e5f8aa83702808ffe039-%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.png)


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
    let lHead = null;
    let node = head;

    while (node) {
        let next = node.next;

        node.next = lHead;
        lHead = node;
        node = next;
    }

    return lHead;
};

```