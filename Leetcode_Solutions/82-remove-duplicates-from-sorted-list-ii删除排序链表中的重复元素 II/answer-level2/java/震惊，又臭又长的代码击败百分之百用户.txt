### 解题思路
就是三个指针一顿乱指，再加上边界条件处理，有一种边界条件是通过递归处理的。

### 代码

```java
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode p = head, c = p.next, pp = head;
        boolean equal = false;
        while (c != null) {
            if (p.val != c.val) {
                if (!equal) {
                    pp = p;
                    p = c;
                    c = p.next;
                } else {
                    equal = false;
                    if (p == head) {
                        return deleteDuplicates(c);
                    } else {
                        pp.next = c;
                        p = c;
                        c = p.next;
                    }
                }
            } else {
                c = c.next;
                equal = true;
            }
        }
        if (equal) {
            if (pp != head || pp.val != p.val) {
                pp.next = null;
                return head;
            }
            return null;
        }
        return head;
    }
}
```