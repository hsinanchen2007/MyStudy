### 解题思路
此处撰写解题思路
执行用时 : 112 ms,内存消耗 : 38.3 MB
def就是为了节省内存开销(浅拷贝注意)，如果要修改数据的话还是直接{ val: 0, next: null }
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
var addTwoNumbers = function (l1, l2) {
    let List = {}, def = { val: 0, next: null }
    let next = function (List1, List2, List3, carry) {
        let val = List1.val + List2.val + carry
        List3.val = val % 10
        if (!List1.next && !List2.next) {
            val >= 10 ? List3.next = { val: 1, next: null } : List3.next = null
            return
        } else {
            List3.next = {}
        }
        next(
            List1.next || def,
            List2.next || def,
            List3.next,
            val >= 10 ? 1 : 0)
    }
    next(l1, l2, List, 0)
    return List
};
```