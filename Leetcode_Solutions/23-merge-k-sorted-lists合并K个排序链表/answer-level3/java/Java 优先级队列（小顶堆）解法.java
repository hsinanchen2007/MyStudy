思路：
建一个初始大小为链表个数 len 的小顶堆，把每个链表的头节点都放入堆中，堆顶的节点就是最小值节点
循环：当堆不为空
从堆顶移除堆顶节点 minNode，加入合并链表的尾部，判断被移除的堆顶节点 minNode 是否有 next 节点，有，把 next 节点加入堆
继续循环

时间复杂度：链表个数为K，小顶堆大小为K，从小顶堆中选出堆顶后重新堆化时间复杂度为O(logK)，所有链表节点总数为N，因此总的时间复杂度是log(NlogK)
空间复杂度：占用了大小为K的堆，空间复杂度O(K)
```
/**
 *
 * 7 ms, 54.46%
 * 42.1 MB, 44.87%
 */
class Solution1 {

    public ListNode mergeKLists(ListNode[] lists) {
        //极端情况处理
        int len = 0;
        if (lists == null || (len=lists.length) == 0) return null;
        if (len == 1) return lists[0];
        //2个或以上个链表的情况
        ListNode preHead = new ListNode(-1);
        ListNode cur = preHead;
        //按节点数值大小比较建立最小堆
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>(len, (n1, n2) -> (n1.val - n2.val));
        for (ListNode list : lists) {
            if (list != null) minHeap.offer(list);
        }
        while (!minHeap.isEmpty()) {
            ListNode minNode = minHeap.poll();
            cur.next = minNode;
            cur = cur.next;
            if (minNode.next != null) {
                minHeap.offer(minNode.next);
            }
        }
        return preHead.next;
    }
}
```
