### 解题思路
使用三个指针来保存当前节点、上一个节点和下一个节点的引用，这样的话就保存了当前节点的前后关系，所以在将当前节点的指向改变为前一个节点时，当前节点的以前的下一个节点可以通过指针来获取。

通过遍历一次链表，就可以完成链表的反转。
空间复杂度：O(n)
时间复杂度：O(1)

注意事项：
1、head可能为null，所以直接获取`head.next`会报错

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
    let prev = null
    let curr = head
    let next = null
    while(curr!=null){
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    }
    return prev
};
```