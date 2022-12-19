相对于数组实现，劣势是从前开始找，优势是不用平移数字，只需改变指针

```
 public static ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode orderedNode = head;
        ListNode cursorNode = head.next;
        // make sure not in cycle
        orderedNode.next = null;

        while (cursorNode != null) {
            ListNode aftNode = cursorNode.next;
            // make sure not in cycle
            cursorNode.next = null;
            // check 两端的情况
            if (cursorNode.val <= head.val) {
                cursorNode.next = head;
                // should update head ref
                head = cursorNode;
            } else if (cursorNode.val >= orderedNode.val) {
                orderedNode.next = cursorNode;
                orderedNode = cursorNode;
            } else {
                ListNode preNode = head;
                ListNode currNode = head;
                while (currNode != orderedNode.next) {
                    if (currNode.val < cursorNode.val) {
                        preNode = currNode;
                        currNode = currNode.next;
                        continue;
                    }

                    preNode.next = cursorNode;
                    cursorNode.next = currNode;
                    break;
                }
            }

            cursorNode = aftNode;
        }

        return head;
    }
```
