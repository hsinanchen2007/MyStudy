### 解题思路
假设输入：1->2->3->4->null
要求获得：4->3->2->1->null
第一步：
    应该获得1->null, 并且下一步要从2开始，生成2->1->null。
    所以有temp = a.next ==> 2->3->4->null
    a.next = b ==>  a = 1->null (用于获得1->null)
    b = a ==> b = 1->null (用作记录)
    a = temp ==> a = 2->3->4->null(继续下一个循环)

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
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
    if (!head) return head;
    let a = head;
    let temp = null;
    let b = null
    while (a) {
        temp = a.next;
        a.next = b;
        b = a;
        a = temp;
    }
    return b;
};
```