![image.png](https://pic.leetcode-cn.com/39d95f3fcd9a7ad628a0765c66b865a22e8831d237a9337178be639e268f595f-image.png)

```
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head == null)
            return null;
        if(head.val == val)
            return removeElements(head.next, val);
        head.next = removeElements(head.next, val);
        return head;
    }
}
```
