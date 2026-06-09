只是看到没有JS的题解。。。加上我刚学习链表，所以献丑写一个js的。


```javascript []
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
    if (l1 === null) return l2
    if (l2 === null) return l1
    let cur_l1 = l1, cur_l2 = l2, l3 = new ListNode('head')
    
    // 如果两个链表都走到了最后，则结束while循环。
    while(!(cur_l1===null && cur_l2===null)) {
        // 将链表2的值更新到L3，并且L2的指针往下走。
	if (!cur_l1 || (cur_l2 && cur_l1.val >= cur_l2.val)) {
	    l3 = listPush(l3, new ListNode(cur_l2.val))
	    cur_l2 = cur_l2.next
        }  else {  // 将链表1的值更新到L3，并且L1的指针往下走。
            l3 = listPush(l3, new ListNode(cur_l1.val))
            cur_l1 = cur_l1.next
        }
    }
    return l3.next
};

function listPush(list, item) {
    let cur = list
    while(cur.next !== null) {
        cur = cur.next
    }
    cur.next = item
    
    return list
}

```
