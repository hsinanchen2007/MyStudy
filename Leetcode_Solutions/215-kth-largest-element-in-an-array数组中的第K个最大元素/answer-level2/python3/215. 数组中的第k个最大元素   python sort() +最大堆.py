### 解题思路

**法一：**
首先很容易想到的是sort()的方法，但是难度为中等的题目应该不至于这样。
sort()方法的时间复杂度为O(N*logN),空间复杂度为O(1)，因为就地排序

**法二：**
这道题可以使用堆来优化，堆比较列表的优势在于，它可以在插入数据时自动调整位置，使之符合堆特征，即nums[i]总是大于nums[i//2]。这里顺便复习下heap的各个函数用法：
    1. heappush(heap, x)                                        将x压入堆中
    2. heappop(heap)                                      从堆中弹出最小的元素
    3. heapify(heap)                                           让列表具备堆特征
    4. heapreplace(heap, x)                      弹出最小的元素，并将x压入堆中，返回弹出的元素
    5. nlargest(n, iter)                                       返回iter中n个最大的元素
    6. nsmallest(n, iter)                                   返回iter中n个最小的元素

其中法二就是采用nlargest直接获取答案

**法三：**
利用最大堆，存储前k个最大的数，最后返回堆底元素就行了。
主要思路：
①当i<k,压数据进堆
②当i>=k，比较sums[i]和堆底元素，如果大于，则使用heapreplace进行替换，否则跳过。        


### 代码

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        from heapq import heappush,heapreplace
        # 普通的sort()方法
        # 时间复杂度O(N*logN),空间复杂度O(1)
        nums.sort()
        return nums[-k]
        
```


```python     
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        from heapq import heappush,heapreplace
        # 使用堆的nlargest(n,iter)返回前n个最大的数,倒序排练
        return nlargest(k,nums)[-1]
    
```


```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        from heapq import heappush,heapreplace       
        # 使用小顶堆
        heap = []
        for i in range(len(nums)):
            if i < k:
                heappush(heap,nums[i])
            else:
                if nums[i] > heap[0]:
                    m = heapreplace(heap,nums[i])
        return heap[0]
```