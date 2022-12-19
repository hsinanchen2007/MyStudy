### 解题思路
参考 https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/shuang-zhi-zhen-fa-lang-man-xiang-yu-by-ml-zimingm/

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
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
        if(!headA || !headB){
        return null
    }
    let node1 = headA
    let node2 = headB

    while(node1 != node2){
        node1 = node1 == null ? headB : node1.next;
        node2 = node2 == null ? headA : node2.next
    }

    return node1;
};
```