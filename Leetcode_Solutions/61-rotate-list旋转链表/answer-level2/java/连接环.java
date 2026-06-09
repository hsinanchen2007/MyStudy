```java
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return head;
        int sum = 1;
        ListNode temp = head;
        while (temp.next != null) {
            temp = temp.next;
            sum++;
        }
        temp.next = head;
        int cursor = sum - (k % sum);
        while (cursor > 1) {
            head = head.next;
            cursor--;
        }
        temp = head.next;
        head.next = null;
        return temp;
    }
```
