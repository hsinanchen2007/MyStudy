
[@philhsu](/u/philhsu/)的实现在所存的map中并没有删去两个前缀和相同的结点之间的结点，导致之后可能某些结点的前缀和错误匹配了本应该被删去的节点，导致代码并不能AC
```
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        Map<Integer, ListNode> prefixSumMap = new HashMap<>();
        ListNode p = dummy;
        int prefixSum = 0;
        while (p != null) {
            prefixSum += p.val;
            if (prefixSumMap.containsKey(prefixSum)) {
                p = prefixSumMap.get(prefixSum).next;
                int val = prefixSum + p.val;
                while (val != prefixSum) {
                    prefixSumMap.remove(val);
                    p = p.next;
                    val += p.val;
                }
                prefixSumMap.get(prefixSum).next = p.next;
            }
            else {
                prefixSumMap.put(prefixSum, p);
            }
            p = p.next;
        }
        return dummy.next;
    }
```