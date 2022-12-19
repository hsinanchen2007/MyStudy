### 解题思路
首先设置一个新的链表l3，以及一个中间变量c3，然后在两链表值中非零的条件下由链表的最小值即第一位展开比较，l1小于l2时，l1的值先赋给c3，l1的值变为链表下一个，依次类推可得，最后考虑长度问题，若剩下一个链表还有多余的，直接补在新生成的链表后即可

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
    var l3 = new ListNode(-1);
    var c3 = l3;
    while(l1 !== null && l2 !== null)
    {
        if(l1.val <= l2.val)
        {
            c3.next = l1;
            l1 = l1.next;
        }
        else
        {
            c3.next = l2;
            l2 = l2.next;
        }
        c3 = c3.next;
    }
    c3.next = (l1 == null) ? l2:l1;
    return l3.next;
};
```