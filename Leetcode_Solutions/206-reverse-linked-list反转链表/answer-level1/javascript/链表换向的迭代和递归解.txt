### 解题思路
此处撰写解题思路

### 代码
第一种迭代法
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
    if(!head) return head;          // 为空的处理
    let next = head.next            // 保存下个节点的引用
    head.next = null                // 第一个node的特殊处理
    while(next) {
        const nextNext = next.next  // 保存下下个节点的引用
        next.next = head            // 换向
        head = next                 // 重新赋值下个节点
        next = nextNext             // 准备下次迭代
    }
    return head
};
```

迭代法

```js
var reverseList = function(head) {
    if (!head || !head.next) return head                // 为空的处理
    function recursive(headNode, nextNode, isFirst) {   // 递归函数, 与迭代一样, 传入currentNode, currentNode.next的引用
        if(!nextNode) return headNode;                  // 迭代结束条件
        if(isFirst) headNode.next = null                // 第一个的特殊处理
        let nextNext                                    // 用于保存下下节点
        if(nextNode.next) {                                  
            nextNext = nextNode.next                   
        }
        nextNode.next = headNode;                       // 换向
        return recursive(nextNode, nextNext)            // 迭代

    }
    return recursive(head, head.next, true)
}
```