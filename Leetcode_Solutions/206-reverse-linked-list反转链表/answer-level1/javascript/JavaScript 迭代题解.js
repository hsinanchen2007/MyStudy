### 解题思路
链表的反转，最先想到的必然是通过迭代，毕竟也有相关的提示。那如何进行迭代呢？
如递归相同，递归总是要确定一个终止条件，迭代也是。链表的迭代是不知道长度的，所以只能使用 `while` 来进行迭代。  
那迭代终止的条件就很明显了，就是当传入的 链表 迭代到其为 `null` 的时候，说明到了链表的尾部。那么就终止迭代。
那迭代体内部就是不断的进行反转，首先是将当前节点的 `next` 指针保存下来。将提前声明的 `result` 赋值给当前节点的
`next`值，同时将当前节点复制给 `result` ,最后更新迭代条件。 

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
    let result = null;

    while(head) {
        let next = head.next;
        head.next = result;
        result = head;
        head = next;
    }
    return result;

};
```