
```class Solution {
    public ListNode swapPairs(ListNode head) {
        // 替换指针。偶数的值，与下一个换。
        ListNode temp = head;
        int index = 0;
        while (temp != null) {
            if (index % 2 == 0) {//偶数
                if (temp.next != null) {
                    int val = temp.val;
                    temp.val = temp.next.val;
                    temp.next.val = val;
                }
            }

            temp = temp.next;
            index++;
        }
        return head;
    }
}
```
