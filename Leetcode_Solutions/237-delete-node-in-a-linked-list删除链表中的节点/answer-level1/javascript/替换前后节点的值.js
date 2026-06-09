### 解题思路
此处撰写解题思路

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
    while(node.next){
        node.val = node.next.val; //如果有下一个的话，用下一个的值替代当前节点的值
        if(!node.next.next){
            node.next = null; //如果下一个节点没有后代了说明是最后一个，因为前面“删除”了一个（实际上没删除只是被替换了）那么最后那个没后代的就可以直接舍弃了
            break;
        }
        node = node.next;
    }
};
```