### 解题思路
此处撰写解题思路

### 代码

```python3
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k=k
        self.nums=nums
        self.sorted_list=[]
        import heapq
        for vals in self.nums:
            if len(self.sorted_list)<self.k:
                heapq.heappush(self.sorted_list,vals)
            elif len(self.sorted_list)>=self.k:
                if vals < self.sorted_list[0]:
                    pass 
                elif vals> self.sorted_list[0]:
                    heapq.heappop(self.sorted_list)
                    heapq.heappush(self.sorted_list,vals)
                    


    def add(self, val: int) -> int:
        import heapq
        if len(self.sorted_list)<self.k-1:
            heapq.heappush(self.sorted_list,val)
            return None
        elif len(self.sorted_list)+1==self.k:
            heapq.heappush(self.sorted_list,val)
            return self.sorted_list[0]
        else:
            if val<self.sorted_list[0]:
                return self.sorted_list[0]
            else:
                heapq.heappop(self.sorted_list)
                heapq.heappush(self.sorted_list,val)
                return self.sorted_list[0]
        

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```
#1 heapq模块的使用
heapq.heappush(list[],value=3)#加元素
heapq.heappop()#去元素
list[0]#最小的元素
思路：在__init__()中初始化，把数组的元素都加到最小堆self.sorted_list=[]中
#2在add函数中需要判断是否足够有k个元素，该判断用下列伪代码来表示：
元素数小于k-1：
    直接加入即可
元素数=k-1：
    加入后返回堆顶元素
元素数==k，再加一个元素后为k+1个：
    与堆顶比较，比堆顶的数字要大，加入堆，去掉堆顶元素