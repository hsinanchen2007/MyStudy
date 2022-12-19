### 解题思路
利用迭代思想，
    ①比较当前节点和下一个节点：
        如果碰到重复节点，移除重复的next节点，并重复①操作；
        如多节点不重复，跳至下一个节点并重复①操作。
    ②跳出循环并返回第一个节点。

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
var deleteDuplicates = function(head) {
    var tmpHead = head
    while(tmpHead != null){
        var next = tmpHead.next
        if(next != null && next.val == tmpHead.val){
                tmpHead.next = next.next;
        } else {
            tmpHead = tmpHead.next
        }
    }
    return head
};
```