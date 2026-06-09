   使用递归记录节点总数，**倒数节点 = 节点总数-当前节点**
使用虚拟头节点辅助计算

``` java
 public ListNode removeNthFromEnd(ListNode head, int n) {
        // 虚拟头节点
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        removeNthFromEnd(dummyHead, n, 1);
        return dummyHead.next;
    }

    /**
     * 
     * @param head
     * @param n  
     * @param level 记录节点顺序
     * @return
     */
    private int removeNthFromEnd(ListNode head, int n, int level) {
        if(head.next == null){
            return level ;
        }
        int max = removeNthFromEnd(head.next, n, level + 1);
        // 最大节点减去最后当前节点
        // level表示当前节点
        if(max - level == n){
            head.next = head.next.next;
        }
        return max;
    }

```
