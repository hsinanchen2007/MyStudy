### 解题思路
javascript实现

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
var mergeTwoLists = function(l1, l2) {//l1,l2是节点，不是整个链表！
    if(!l1){//l1没有length属性！
        return l2;
    }
    if(!l2){
        return l1;
    }
    if(l1.val < l2.val){
        //递归！！l1.next决定下一个节点！
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    }else{
        l2.next = mergeTwoLists(l1, l2.next,);
        return l2;
    }
};
```