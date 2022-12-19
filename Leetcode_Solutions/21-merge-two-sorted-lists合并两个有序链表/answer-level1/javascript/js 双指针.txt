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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if (!l1 && !l2) return null;
    if (!l1) return l2;
    if (!l2) return l1;
    let res, cur, lh = l1, rh = l2;
    if (lh.val < rh.val) {
        res = lh;
        lh = lh.next;
    } else {
        res = rh;
        rh = rh.next;
    }
    cur = res;
    while (lh || rh) {
        if (lh && rh) {
            if (lh.val < rh.val) {
                cur.next = lh;
                lh = lh.next;
            } else {
                cur.next = rh;
                rh = rh.next;
            }
            cur = cur.next;
        } else {
            cur.next = lh || rh;
            return res;
        }
       
    }
    
};
```