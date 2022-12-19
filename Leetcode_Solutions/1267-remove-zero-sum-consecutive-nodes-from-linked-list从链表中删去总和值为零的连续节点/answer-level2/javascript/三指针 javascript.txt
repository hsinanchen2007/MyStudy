![image.png](https://pic.leetcode-cn.com/fd4ae8fdff430b821bb686e9a55eff38021e38044f16b7b55dc7bb996b011ac5-image.png)


```
    var removeZeroSumSublists = function(head) {
        if (!head.next) {
            if (head.val == 0)
                return null;
            else
                return head;
        }
        let newhead = new ListNode(null);
        newhead.next = head;
        let h = newhead;
        mywhile:
            while (h.next) {
                let p = h.next;
                if (p.val == 0) {
                    h.next = p.next;
                    continue;
                }
                let q = p.next,
                    sum = p.val;
                while (q) {
                    sum += q.val;
                    if (sum == 0) {
                        h.next = q.next;
                        continue mywhile;
                    } else
                        q = q.next;
                }
                h = h.next;
            }
        return newhead.next;
    };
```
