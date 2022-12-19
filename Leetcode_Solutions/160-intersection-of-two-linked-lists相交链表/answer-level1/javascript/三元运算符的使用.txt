### 使用双指针法

### 本来的写法：啰嗦、笨重

```
var getIntersectionNode = function(headA, headB) {
    var PA = headA;
    var PB = headB;
    if(headA == null || headB == null) 
        return null;
    while(PA != null && PB != null) {
        PA = PA.next;
        PB = PB.next;
    }
    if(PA == null) {
        PA = headB;
    } else {
        PB = headA;
    }
    while(PA != null && PB != null) {
        PA = PA.next;
        PB = PB.next;
    }
    if(PA == null) {
        PA = headB;
    } else {
        PB = headA;
    }
    while(PA != PB) {
        PA = PA.next;
        PB = PB.next;
    }
    return PA
};

```
### 参照评论大神的写法，巧妙运用三元运算符

```
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
    var PA = headA;
    var PB = headB;
    // 注意：写程序一定要考虑特殊情况
    if(headA == null || headB == null) 
        return null;
    while(PA != PB) {
        PA = PA == null ? headB : PA.next;
        PB = PB == null ? headA : PB.next;
    }
    return PA
};


```