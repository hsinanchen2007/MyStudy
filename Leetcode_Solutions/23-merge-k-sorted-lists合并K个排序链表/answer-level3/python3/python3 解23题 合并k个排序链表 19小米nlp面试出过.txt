解题：
对于多路归并排列，我们可以使用优先队列解决。我们首先想到的解法是，依次将list中的ListNode弹出，然后一次添加到一个优先队列中，最后将优先队列中ListNode依次弹出，并且添加到result中即可。
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        import heapq      
        min_heap = []  # 用一个列表创建堆
        x = 0
        for i in lists:
            while i:
                heapq.heappush(min_heap, (i.val, x, i))  # 将lists中节点全部弹出，放入一个堆（优先队列）中。
                i = i.next
                x += 1
                # 这里的x变量是为了解决python3比较时报错的问题。
                
        result = ListNode(-1)  # 创建一个头结点
        head = result  # 定义一个指针指向头结点
        
        while min_heap:
            head.next = heapq.heappop(min_heap)[2]
            head = head.next

        return result.next