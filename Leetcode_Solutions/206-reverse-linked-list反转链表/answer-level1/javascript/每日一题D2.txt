**迭代**

- 初始化节点直接指向` null`
- 将当前的节点 ` cur ` 指向前一个节点 `prev`
- 将当前的节点 ` cur ` 和前一个节点 `prev` 都后移一位，得到新的 ` cur ` 和 `prev`，重复前一步骤
**注意**：这一步的后移需要提前将 ` cur.next `存放好，因为` cur`要指向`prev` ，会修改 ` cur.next `的内容
- 当 ` cur ` 为 ` null` 时停止

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let prev = null;
    let cur = head;
    while(cur != null){
        let next = cur.next;
        cur.next = prev;
        prev = cur;
        cur = next
    }
    return prev;
};
```

**递归**

从原链表的最后两个节点开始操作

- 递归到最后的节点时，直接返回节点本身
- 暂存` head.next `的内容，并用` head.next `进行函数递归
- 断开` head `原来的链接，将` head.next `指向` null `
- 将之前存放的` head.next `指向` head `

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if(!head || !head.next){
        return head
    }else{
        let nextNode = head.next;
        reverseNode = reverseList(nextNode);
        head.next = null;
        nextNode.next = head;
        return reverseNode
    }
};
```