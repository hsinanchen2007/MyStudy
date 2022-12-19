```
var sortList = function(head) {
        if (!head || !head.next)
            return head;
        let slow = head,
            fast = head;
        while (slow.next && fast.next && fast.next.next) {
            slow = slow.next;
            fast = fast.next.next;
        }
        let mid = slow.next;
        slow.next = null;
        let right = mid;
        let left = head;
        return merge(sortList(left), sortList(right));
    };
    let merge = function(left, right) {
        let res = new ListNode(null);
        let p1 = left,
            p2 = right;
        let p = res;
        while (p1 && p2) {
            if (p1.val < p2.val) {
                let s = p1;
                p1 = p1.next;
                s.next = null;
                p.next = s;
                p = s;
            } else {
                let s = p2;
                p2 = p2.next;
                s.next = null;
                p.next = s;
                p = s;
            }
        }
        if (p1)
            p.next = p1;
        if (p2)
            p.next = p2;
        return res.next;
    }
```
