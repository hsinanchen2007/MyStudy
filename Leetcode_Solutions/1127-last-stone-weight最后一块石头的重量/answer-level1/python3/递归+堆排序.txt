# 使用递归的解法如下
# 每次对stones进行排序并输出x和y，直到stoens的长度为0或者1时为止
         if len(stones) == 1:
             return stones[0]
         elif len(stones) == 0:
             return 0
         stones = sorted(stones)
         y = stones.pop(-1)
         x = stones.pop(-1)
         if x != y:
            stones.append(y - x)
         return self.lastStoneWeight(stones)
        
# 使用heapq
# 设置一个堆存储所有的数据，将最小的依次弹出并比较大小
        import heapq
        
        stones = [i * -1 for i in stones]
        heap = []
        for stone in stones:
            heapq.heappush(heap, stone)
        
        while heap:
            if len(heap) == 1:
                return heap[0] * (-1)
            y = heapq.heappop(heap)
            x = heapq.heappop(heap)
            if x != y:
                heapq.heappush(heap, y - x)
        return 0