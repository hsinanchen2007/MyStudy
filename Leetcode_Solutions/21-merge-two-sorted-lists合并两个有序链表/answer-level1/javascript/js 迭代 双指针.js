### 解题思路
![image.png](https://pic.leetcode-cn.com/28c8aba94557a459eaa17a87e0480501b1899c916a2772feee0d5f09a6b5a07d-image.png)

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
    let res, cur;
    if (l1.val < l2.val) {
        res = l1;
        l1 = l1.next;
    } else {
        res = l2;
        l2 = l2.next;
    }
    cur = res;
    while (l1 && l2) {
        if (l1.val < l2.val) {
            cur.next = l1;
            l1 = l1.next;
        } else {
            cur.next = l2;
            l2 = l2.next;
        }
        cur = cur.next;
    }
    cur.next = l1 || l2;
    return res;
    
};
```