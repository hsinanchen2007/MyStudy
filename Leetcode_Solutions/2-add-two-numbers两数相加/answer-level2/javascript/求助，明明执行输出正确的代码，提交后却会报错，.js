var addTwoNumbers = function(l1, l2) {
    var head = new ListNode()
    var result = head
    let a1 = l1 , a2 = l2
    var carry = 0
    while(a1 || a2) {
        let sum = a1.val + a2.val + carry //报错为此处"cannot read property 'val' of null"
        carry = sum > 9 ?           //哪怕输出a1也会输出ListNode对象，val也不为空，但a1.val + a2.val就是会报错，
        result.next = new ListNode(carry ? sum % 10 : sum)
        result = result.next 
        a1 = a1.next
        a2 = a2.next
    }
    return head.next
};