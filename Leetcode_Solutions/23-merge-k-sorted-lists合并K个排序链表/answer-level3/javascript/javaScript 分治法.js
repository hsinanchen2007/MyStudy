### 解题思路
# 分治法
**太流弊了**

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
// 连接两个链表的方法
var mergeList = function(l1,l2) {
    if(l1 == null) return l2;
    if(l2 == null) return l1;
   // 哨兵结点
   let pre = { next : null };
   let curr = pre;
   while(l1 !== null && l2 !== null) {
       if(l1.val <= l2.val) {
           pre.next = l1;
           l1 = l1.next;
       } else if(l1.val > l2.val){
           pre.next = l2;
           l2 = l2.next;
       }
       pre = pre.next;
   }
   pre.next = l1 || l2;
   return curr.next;
}
var mergeKLists = function(lists) {
    if(lists.length == 0 || lists == null) return null;
    let left = 0;
    let right = lists.length - 1;
    while(right > 0) {
        while(left < right) {
            lists[left] = mergeList(lists[left],lists[right]);
            left++;
            right--;
        }
        left = 0;
    }
    return lists[0];
};
```