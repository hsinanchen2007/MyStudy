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
    if(!l1) {
        return l2;
    }
    if(!l2) {
        return l1;
    }      
    const res = {};
    let temp = res;
    let a = l1;
    let b = l2;
    // 合并过程类似于，ag: 输入：1->2->4, 1->3->4
    // (1)->2->4
    // 1->(1)->3->4（第二个链表直接接上去）
    // 1->1->(2)->4（第1个链表剩余直接接上去）
    // 1->1->2->(3)->4（第2个链表剩余直接接上去）
    // 1->1->2->3->4->4   
    // 当两个链表长度相差很大时，且两个链表相交很早时，就很剩时间
    while(a && b) {
        if (a.val < b.val) {
            temp.next = a;
            a = a.next;
        } else {
            temp.next = b;
            b = b.next;
        }
        temp = temp.next;
    }
    // 收尾，将a 或则b 没遍历到的拼接上去
    temp.next = a ? a : b;
    // 而下面的解法是相当原始的，是取值去拼接新的链表，因为涉及到很多有效性判断，所以有很多边界条件
/*  while(a || b) {
        let flaga = a && typeof a.val !== 'undefined';
        const flagb = b && typeof b.val !== 'undefined';
        if(flaga && (!flagb || a.val <= b.val)) {
            temp.val = a.val;
            a = a.next;
            if (a || flagb) {
                temp.next = {};
                temp = temp.next;
                flaga = a && typeof a.val !== 'undefined';
            }
        }
        if(flagb && (!flaga || b.val <= a.val)) {
            temp.val = b.val;
            b = b.next;
            if (a || b) {
                temp.next = {};
                temp = temp.next;
            }
        }       
    }
     */
    return res.next;
};


```