var addTwoNumbers = function(l1, l2) {
    const l = new ListNode(0);
    let high = 0;
    let node = l;
    while (l1 !== null || l2 !== null) {
        if (l1 === null) {
            high += l2.val;
            l2 = l2.next;
        }
        else if (l2 === null) {
            high += l1.val;
            l1 = l1.next;
        }
        else {
            high += (l1.val + l2.val);
            l1 = l1.next;
            l2 = l2.next;
        }
        node.next = new ListNode(high % 10);
        node = node.next;
        high = high > 9 ? 1 : 0;
    }
    if (high !== 0) {
        node.next = new ListNode(high);
    }
    return l.next;
};