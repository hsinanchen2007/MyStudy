一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
思路1:
- 用快排partition划分，一直划中第k个数 最差情况o(kn)

思路2：
- 最小堆建立(需要o(n)时间复杂度) 
- 取出前k个数(每次取需要用logn时间重建堆)。时间复杂度为o(n)+o(k*logn)

### 代码

思路1代码：
```python
def partition(input, low, high):
    pivot = input[low]
    while low < high:
        while low < high and pivot <= input[high]:
            high -= 1
        input[low] = input[high]
        while low < high and pivot >= input[low]:
            low += 1
        input[high] = input[low]
    input[low] = pivot
    return low

class Solution(object):
    def getLeastNumbers(self, tinput, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k > len(tinput) or k <= 0: return []
        idx = partition(tinput, 0, len(tinput) - 1)
        low = 0
        high = len(tinput) - 1
        while idx != k - 1:
            if idx < k - 1:
                low = idx + 1
                idx = partition(tinput, low, high)
            if idx > k - 1:
                high = idx - 1
                idx = partition(tinput, low, high)
        return tinput[:k]
```

思路2代码：
```python
def sink(array, k):
    n = len(array)
    left = 2 * k + 1
    right = 2 * k + 2
    if left >= n: return
    min_i = left 
    if right < n and array[left] > array[right]:
        min_i = right
    if array[min_i] < array[k]:
        array[min_i], array[k] = array[k], array[min_i]
        sink(array, min_i)

def build_heap(list):
    n = len(list)
    for i in range(n//2, -1, -1):
        sink(list, i)

    return list

def GetLeastNumbers_Solution(tinput, k):
    if k > len(tinput): return []
    heap = build_heap(tinput)  # 建堆o(n)复杂度
    res = []
    for _ in range(k):  # 取topk o(klogn)复杂度
        heap[0], heap[-1] = heap[-1], heap[0]
        res.append(heap.pop())
        sink(heap, 0)
    return res
```