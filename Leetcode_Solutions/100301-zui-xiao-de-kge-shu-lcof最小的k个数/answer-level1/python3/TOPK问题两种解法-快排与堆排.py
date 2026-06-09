### 解题思路
此处撰写解题思路

### 代码

```python3
import heapq
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        """
        使用堆排序算法: 
        1. 首先利用前k个数构建一个容量为k的大顶堆；
        2. 然后将剩下的len(arr) - k 个元素逐一入堆：
            2.1 如果新增加的元素n比堆顶元素小，则将堆顶元素删除，将元素n入堆（添加元素n后重新堆化）
            2.2 如果新增加的元素n比对顶元素大，则不对堆做任何操作，跳过该步骤
        3. 步骤2执行完毕后，堆中保留的元素则为最小的k个元素
        """
        if k == 0 or not arr:
            return []
        topk = [-x for x in arr[:k]] # python 默认是小顶堆，因此需要取反(此时的堆顶元素其实是对应的最大值)
        heapq.heapify(topk) # 堆化
        for value in arr[k:]:
            if topk[0] <= -value: # tokp[0] 为堆顶元素，判断堆顶元素与新增的元素n的大小
                heapq.heappop(topk) # 弹出堆顶元素
                heapq.heappush(topk, -value) # 新增元素n入堆
        return [-i for i in topk] # 堆中保留的元素为最小的k个元素
                
    def getLeastNumbers_by_quicksort(self, arr: List[int], k: int) -> List[int]:
        # 使用快速排序，然后选择前k个最小的点
        def _quick_sort(array):
            if len(array) <= 1:
                return array
            else:
                pivot = array[len(array)//2] # 选择一个基准值
                less = [i for i in array if i < pivot]
                middle = [i for i in array if i == pivot]
                greater = [i for i in array if i > pivot]
                return _quick_sort(less) + middle +  _quick_sort(greater)      
        res = _quick_sort(arr)
        return res[:k]

```