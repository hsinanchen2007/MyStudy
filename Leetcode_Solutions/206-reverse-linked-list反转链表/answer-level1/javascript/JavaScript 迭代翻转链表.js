```
const reverseList = (head) => {
  // 假设head为null，则直接返回null
  if (head === null) {
    return null;
  }
  // 创建一个变量，用来保存当前操作的节点
  let currentNode = new ListNode(head.val);
  // 将head赋值为head的下一个元素，如果不为null
  while ((head = head.next) !== null) {
    // 创建一个变量，用来保存currentNode的上一个元素
    const previousNode = new ListNode(head.val);
    // 将previousNode的下一个元素设置成currentNode
    previousNode.next = currentNode;
    // 把currentNode赋值为previousNode，为了下一次迭代
    currentNode = previousNode;
  }
  // 迭代完head链表，同时也将链表翻转了
  // currentNode即为新链表中的第一个元素
  return currentNode;
};
```
