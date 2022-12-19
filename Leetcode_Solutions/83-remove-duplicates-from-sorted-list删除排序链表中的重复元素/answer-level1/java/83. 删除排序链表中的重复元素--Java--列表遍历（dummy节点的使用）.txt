[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_83_deleteDuplicates.java)

```java
    /**
     * 解题思路：典型的列表遍历
     *
     * @param head
     * @return
     */
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode next = head;
        ListNode preEqual;
        while (next != null) {
            preEqual = next.next;
            while (preEqual!=null&&preEqual.val == next.val){
                preEqual = preEqual.next;
            }
            next.next = preEqual;
            next = preEqual;
        }

        return dummy.next;
    }
```