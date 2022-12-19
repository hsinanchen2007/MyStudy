注册LeetCode好久，今晚第一次刷题，第一次击溃了100%用户，这是真的吗？

```java
class Solution {
    public int[] reversePrint(ListNode head) {
        ListNode saved = head;
        ListNode saved2 = head;
        int length = 0;
        while (saved2 != null) {
            ++length;
            saved2 = saved2.next;
        }

        int[] arr = new int[length];
        while (saved != null) {
            arr[--length] = saved.val;
            saved = saved.next;
        }
        return arr;
    }
}
```