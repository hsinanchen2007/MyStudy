1、嵌套循环

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
    if(!headA || !headB) return null;
    while(headA) {
        var temp = headB; // 为啥直接用headB做循环不行
        while(temp){
            if(temp === headA) return headA;
            temp = temp.next
        }
        headA=headA.next;
    }
    return null;
};
```
时间复杂度 : O(m*n)
空间复杂度 : O(1)

2、使用哈希
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
     if(!headA || !headB) return null
    // 在set结构中没有键名，只有键值，所以set.keys() == set.values(),且默认遍历的是调用values()方法,map是有键名和键值的。
    let set = new Set();
    while(headA) {
        set.add(headA)
        headA=headA.next;
    }
    while(headB) {
        if(set.has(headB)) return headB;
        headB = headB.next;
    }
    return null;
};
```
时间复杂度 : O(n+m)
空间复杂度 : O(m)或O(n)

3、双指针
可以理解为两个链表AB和BA,他们两的长度一定相等，因此可以同时走，直到找到相等的位置
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
    if(!headA || !headB) return null
    let pA = headA;
    let pB = headB;
    while(pA != pB){
        pB = pB? pB.next: headA;
        pA = pA? pA.next: headB;
    }
    return pA;
};
```
时间复杂度 : O(n+m)
空间复杂度 : O(1)