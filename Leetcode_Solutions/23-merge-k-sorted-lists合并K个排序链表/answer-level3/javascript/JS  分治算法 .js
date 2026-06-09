### 解题思路
分治算法的JS版本
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
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    if(lists.length <= 0){
        return null;
    }
    function mergeTwoLists(l1, l2){
        if(l1 == null){
            return l2;
        }
        if(l2  == null){
            return l1;
        }
        let head = new ListNode(null);
        let now = head;
        while(l1 != null && l2 != null){
            now.next = new ListNode(null);
            now = now.next
            if(l1.val <= l2.val){
                now.val = l1.val;
                l1 = l1.next;
            }else{
                now.val = l2.val;
                l2 = l2.next;
            }
        }
        now.next = l1 != null ? l1 : l2;
        return head.next;
    }
    let jump = 1;
    while(jump < lists.length){
        for(let i = 0; i < lists.length; i = i + 2 * jump){
            lists[i] = mergeTwoLists(lists[i], lists[i+jump]);
        }
        jump *= 2;
    }
    return lists[0];
};
```