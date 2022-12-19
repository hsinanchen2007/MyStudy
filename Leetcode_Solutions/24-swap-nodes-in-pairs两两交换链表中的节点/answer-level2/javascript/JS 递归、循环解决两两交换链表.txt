### 解题思路

跟简单反转的链表的区别就是需要在循环内保留两个指针，两个节点往前进，每两个节点在循环内做反转。另外，跟简单反转链表不同的就是需要定义一个节点作为保存头节点的方式，在循环后进行返回

### 循环解法

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
var swapPairs = function(head) {
    let pHead = new ListNode(null)
    pHead.next = head
    let prev = pHead

    while(head && head.next) {
        let firstNode = head
        let secondNode = head.next
        let tmp = secondNode.next
        prev.next = secondNode
        secondNode.next = firstNode
        firstNode.next = tmp

        head = tmp
        prev = firstNode
    }

    return pHead.next
};
```

### 递归解

 递归的核心是要做任务拆解，弄清楚当前阶段的任务、下一阶段的任务、什么时候停止。本题当前阶段的任务就是反转两个节点，下一阶段的任务 是反转第三个之后的链表，并将顺序调整过的链表赋值给第二个节点的 next

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (!head || !head.next) return head

    let tmp = head.next
    head.next = head.next.next
    tmp.next = head
    head.next = swapPairs(head.next)
    return tmp
};
```