### 解题思路
此处撰写解题思路
**1** 下面演示了链表变化的过程，主要是将后一个值赋给前一个，然后将下下一个的节点连到当前指向的节点上。看到这个解法感到很精髓。
![image.png](https://pic.leetcode-cn.com/b4a6d8b7c117b166e421f1c19cd31b14117a66cee53401693854f06de98620f2-image.png)

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
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */

var deleteNode = function(node) {
    node.val = node.next.val; //将指向节点的下一个节点的值赋给该节点
    node.next = node.next.next;//然后将指向节点连到下下一个节点
};

```