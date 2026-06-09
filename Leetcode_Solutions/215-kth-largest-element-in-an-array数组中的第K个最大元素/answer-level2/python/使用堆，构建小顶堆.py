        import  heapq
        self.pool = []
        if not nums:
            return 0
        n = len(nums)
        if k > n:
            return False
        for i in range(k):
            heapq.heappush(self.pool,nums[i]) # 将前k个存在堆中，
        heapq.heapify(self.pool)# heapq.heapify，调整成小顶堆
        for j in range(k,n):# 对剩下的一次遍历， 检验与堆顶的关系
            if nums[j] <=self.pool[0]:
                continue
            else:# nums[j] > self.pool[0]
                heapq.heapreplace(self.pool,nums[j])#若是当前的值大于堆顶，就取代堆顶，再调整堆
                heapq.heapify(self.pool)
        print(self.pool)
        return self.pool[0]
