### 解题思路
此处撰写解题思路
这道题主要思路是确定三个点：前一个节点（prev），当前节点（cur），后一个节点（temp），
每次循环，缓存后一个节点，把前一个节点赋值给当前节点的next，prev和cur依次往前移动一位
起始条件: cur = head
终止条件: cur===null

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
    let prev = null;
    let cur = head;
    while(cur!==null){
        let temp = cur.next
        cur.next = prev
        prev = cur
        cur = temp
    }
    return prev
};
```