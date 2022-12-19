### 解题思路
通过构造k个元素的大根堆来存储最小的k个元素，步骤如下：
1. 取数组前k个元素初始化堆，从最后一个非叶结点开始到根结点来构建最大堆
2. 当某个元素大于堆顶元素时，直接抛弃
3. 当某个元素小于堆顶元素时，替换堆顶元素，再从堆顶重新构建最大堆

使用python标准库heapq.nsmallest(k, arr)一行代码就可以解决
好久不写堆排序，练习一下，使用列表来模拟堆

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not arr or k == 0: return []
        if len(arr) <= k: return arr
        heap = arr[:k]
        def buildMaxHeap(pos):
            while pos*2+1 < k:
                max_pos = pos*2+1
                if pos*2+2 < k and heap[pos*2+2] > heap[pos*2+1]:
                    max_pos += 1
                if heap[pos] < heap[max_pos]:
                    heap[pos],heap[max_pos] = heap[max_pos],heap[pos]
                    pos = max_pos
                else: break
        
        for i in range(k//2, -1, -1):
            buildMaxHeap(i)
        for i in range(k, len(arr)):
            if arr[i] < heap[0]:
                heap[0] = arr[i]
                buildMaxHeap(0)
            else: continue
        return heap
```