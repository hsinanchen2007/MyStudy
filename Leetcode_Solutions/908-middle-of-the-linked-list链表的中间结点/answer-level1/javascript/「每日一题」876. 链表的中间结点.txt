### 解题思路
#### 数组求解
通过数组记录下每个节点，通过数组的长度取中间节点
#### 快慢指针
快指针，每次访问两个节点
慢指针，每次访问一个节点
如果快指针遍历完整个链表，则慢指针刚好指向中间节点
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
/**
 * 数组
 * 通过数组记录下每个节点，通过数组的长度取中间节点
 */
var middleNode = function(head) {
    let list = [];
    getListNode(head, list);
    let len = list.length;
    return len%2 === 0? list[len/2 - 1] : list[(len - 1)/2];
};
// 递归每一个ListNode
function getListNode (listNode, list){
    if(listNode.next != null){
        getListNode(listNode.next, list);
    }
    // list数组中存储的是链表节点的倒序
    list.push(listNode);
}
/**
 * 快慢指针
 * 快指针，每次访问两个节点
 * 慢指针，每次访问一个节点
 * 如果快指针遍历完整个链表，则慢指针刚好指向中间节点
 */
var middleNode = function(head) {
    // step1 步进 1 的慢指针，step2 步进 2 的快指针
    let step1 = head; step2 = head;
    while(step2 && step2.next){
        step1 = step1.next;
        step2 = step2.next.next;
    }
    return step1;
};
```