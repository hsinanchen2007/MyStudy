直接上代码吧

```
    /**
     * 你能用 O(1)（即，常量）内存解决此问题吗？
     * 能：
     * 思路：每次遍历是，断开他的next节点，并且将val设置为一个特殊值
     * 当遍历到尾部，走到下一个环的连接点时，next=null && val=特殊值，就说明这个访问过，直接返回true即可
     *
     * @param head
     * @return
     */
    public boolean hasCycle(ListNode head) {
        ListNode temp;
        while (head != null) {
            if (head.next == null && head.val == Integer.MIN_VALUE) {
                return true;
            }
            temp = head.next;
            head.next = null;
            head.val = Integer.MIN_VALUE;
            head = temp;
        }
        return false;
    }
```
