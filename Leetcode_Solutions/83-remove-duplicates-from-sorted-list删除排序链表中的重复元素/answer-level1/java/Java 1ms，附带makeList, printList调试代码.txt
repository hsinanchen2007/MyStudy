在遍历时嵌套内层循环，找出当前重复数字的最后一位，找到后返回大循环
```
public ListNode solution(ListNode head) {
        ListNode origin = head;
        int currentVal = Integer.MIN_VALUE;
        while (head != null && head.next != null) {
            if (head.val != currentVal) {
                currentVal = head.val;
            }
            ListNode temp = head.next;
            while (temp.val == currentVal) {
                temp = temp.next;
                if (temp == null) {
                    break;
                }
            }
            head.next = temp;
            head = head.next;
        }
        return origin;
    }
```

以下为makeList & printList代码，可以方便大家在本地调试
makeList调用示例makeList("11233");
```
    public ListNode makeList(String s) {
        ListNode start = new ListNode(-1);
        ListNode p = start;
        for (char ch : s.toCharArray()) {
            start.next = new ListNode(ch - '0');
            start = start.next;
        }
        return p.next;
    }

    public String printList(ListNode head) {
        String result = "";
        while (head != null) {
            result += head.val;
            result += head.next == null ? "" : "->";
            head = head.next;
        }
        return result;
    }
```
