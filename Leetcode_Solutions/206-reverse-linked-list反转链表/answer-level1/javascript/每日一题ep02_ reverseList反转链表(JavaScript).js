// ### 解题思路
// **递归法**
// 利用**递归**将 next 进行反转链表，当前节点=head.next. 
// 时间复杂度: O(n). n-1 层递归，每层时间复杂度均为 O(1)
// 空间复杂度: O(n). n-1 层递归

// ### 代码

// ```javascript
var reverseList = function(head) {
    if(!head||!head.next){
        return head
    }
    let next = head.next //next ->reversed ->head.next
    let rHead = reverseList(next)
    head.next = null //cut head
    next.next = head //back to front
    return rHead
};

// ```
// 😀