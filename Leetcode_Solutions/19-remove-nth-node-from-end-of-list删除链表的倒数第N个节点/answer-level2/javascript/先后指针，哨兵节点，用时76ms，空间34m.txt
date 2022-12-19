var removeNthFromEnd = function(head, n) {
    head = {
        val: null,
        next: head
    }
    if (head.next === null) {
        return null
    }
    let current = head
    let current2 = head
    let i = 0
    while(i < n && current.next !== null) {
        i++
        current = current.next
    }
    while(current && current.next !== null) {
        current = current.next
        current2 = current2.next
    }
    current2.next = current2.next.next
    return head.next
};