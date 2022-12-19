### 解题思路
此处撰写解题思路
[@guanpengchn](/u/guanpengchn/)
抄大佬作业
递归有点像队列，根据执行顺序依次将当前的执行环境及变量等放进队列里，根据最后的递归出口，最后一个进入队列的执行环境最先得到结果。后进先出。
根据代码逻辑，依次得到各个执行环境结果。类似于reduce函数，层层递进得到最终结果。
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
    if (l1 === null) return l2
    if (l2 === null) return l1
    
    if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2)
        return l1
    } else {
        l2.next = mergeTwoLists(l1, l2.next)
        return l2
    }
    
 
};
```