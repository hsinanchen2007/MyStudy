### 解题思路
迭代和递归是一样的思想，一个一个的处理
当某一个是null的时候，直接把另一个拼接到下边就好了

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let node = new ListNode(-1)
    let temp = node
    while(l1 !=null && l2 !=null){
       
        if(l1.val < l2.val){
            node.next = l1
            node = l1
            l1 = l1.next
        }else{
            node.next = l2
            node = l2
            l2 = l2.next
        }
       
    }
    l1 != null ? node.next = l1 : node.next =  l2

    return temp.next

};
```