javascript的几个答案没太看明白，参考了精选图解，实现javascript版，比如容易理解

![image.png](https://pic.leetcode-cn.com/df25831a5e084d12e84f5ea0290b567a6587a128fb8a369772f6a11dad8faa29-image.png)

```
var reverseKGroup = function(head, k) {
    let thead = new ListNode(0)
    thead.next = head
    let pre = thead
    let end = thead
    while (end.next !== null) {
        for (let i = 0; i < k && end !== null; i++) {
            end = end.next
        }
        if (end == null) break
        let start = pre.next
        let next = end.next
        end.next = null
        pre.next = reverse(start)
        start.next = next
        pre = start
        end = pre
    }
    return thead.next
};

function reverse(head) {
    if (head === null) {
        return head
    }
    let cur = head
    let pre = null
    while (cur) {
        [cur.next, pre, cur] = [pre, cur, cur.next]
    }
    return pre
}
```
