### 解题思路
删除节点有两种思路：
1.将前一个指向后一个，这种方式需要保存前一节点的指针，
2.将后一个元素值复制到当前位置，然后按照第一种方式删除后一个元素
此处并没有保存前一节点指针，所以只能采用第二种思路

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
   if(node.next){
       //后一个节点不是null
        node.val=node.next.val
        node.next=node.next.next
   }else{
       //后一个节点是null
       node=null
   }
};
```