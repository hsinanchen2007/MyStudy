### 解题思路
直接遍历两个链表相加，如果有链表较短，直接补0
注意保存头结点

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
var addTwoNumbers = function(l1, l2) {
    let temp = new ListNode(-1)
    let cur = temp
    let c = 0
    while(l1 != null || l2 != null){
        let v1 = l1 == null ? 0 : l1.val
        let v2 = l2 == null ? 0 : l2.val
        let v = v1 + v2 + c
        c = v >=10 ? 1: 0
        cur.next = new ListNode(v%10)
        cur = cur.next

        if(l1 != null){
            l1 = l1.next
        }
        if(l2 != null){
            l2 = l2.next
        } 
    }
    if(c ==1){
        cur.next = new ListNode(1)
    }
    return temp.next
};
```