**解题思路：**因为题目给出的各个链表已经是排好序的，所以在利用各个链表的头结点建立最小堆之后，依次弹出堆顶元素，并将该元素的下一个结点加入堆中即可。因为要遍历所有结点，所以要调用n（n为结点总数）次堆，每次堆操作的时间复杂度为log（k），所以总体时间复杂度为O（nlog(k)）

## 示例代码

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        #定义最小堆：
        heap = []
        #定义结果链表
        res = ListNode(None)
        
        #考虑边界条件：
        if len(lists) == 0:
            return None
        if len(lists) == 1:
            return lists[0]
        
        #依次将头结点加入最小堆
        for head in lists:
            if head == None:
                continue
            #结点无法比较大小，需要在堆中存放元组
            heapq.heappush(heap, (head.val, head))
        #标记返回位置
        if len(heap) == 0:
            return None
        start = heap[0][1]
        
        #当链表不为空：
        while len(heap) != 0:
            val, node = heapq.heappop(heap)
            res.next = node
            res = node
            if node.next == None:
                continue
            #压入弹出结点的下一个结点
            heapq.heappush(heap, (node.next.val, node.next))
        
        return start