### 1. 使用python内置函数 sort() 求解
![image.png](https://pic.leetcode-cn.com/f6ce6a850088d0ca946d1bcb7e1d8952c9d4cd12531b0cb2290e91e028b562bb-image.png)

- 简单粗暴直接进行排序,取前 K 个即可. sort()函数使用 Timsort 方法进行排序,时间复杂度O(NlogN),也很不错啦!!

### 代码
```
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        arr.sort()
        return arr[:k]
```

### 2. partition方法(基于快速排序)
![image.png](https://pic.leetcode-cn.com/0bc14d9abeb67aa3566fbb9650459c5201560864e3430a2dd3c1d183b63dfe26-image.png)

- 这个其实就是快速排序的思想了,我们要找其中 K 个最小的元素,而快速排序则是没一回合都根据基础数分成两个部分,左边的小于基础数,右面的大于基础数.
- 根据这个思想我们可以找每次排序完,如果基础数的坐标 i 恰好等于 k ,那么我们就可以确定 arr[:k]就是我们的解

### 代码
```
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        # 方法一:partition方法(基于快速排序)
        if k > len(arr) or k <= 0:
            return [] 
        start = 0
        end = len(arr) - 1
        index = self.quickSort(arr, start, end)
        while index != k-1:
            print(index)
            if index > k-1:
                end = index - 1
                index = self.quickSort(arr, start, end)
            if index < k-1:
                start = index + 1
                index = self.quickSort(arr, start, end)
        return arr[:k]

    def quickSort(self, arr, start, end):
        low = start
        high = end
        temp = arr[start]
        while low < high:
            while low < high and arr[high] >= temp:
                high -= 1
            arr[low] = arr[high]
            while low <high and arr[low] < temp:
                low += 1
            arr[high] = arr[low]
        arr[low] = temp
        return low
```





### 3. 大根堆方法
![image.png](https://pic.leetcode-cn.com/e95872750d525f38400f84eda3cf47e7cc2155331cf12d21fe2cdaf6ee415094-image.png)

- 使用堆这个方法可以有两种解题的思路:
1. 思路一: 将全部的数据进行大根堆的排序,然后循环逐一取出前 K 个大的元素,不需要使用额外辅助空间,时间复杂度为O(KlogN)
2. 思路二: 将给定数组前 K 个数据进行大根堆 heap 的排序,然后从第 i = k+1 个元素开始跟大根堆的第一个元素,也就是当前 K 个元素里面的最大值进行比较:
- 当 arr[i] < heap[0] 时,我们将交换这两个元素,重新进行大根堆的排序,如此进行 n-k 次,我们的堆中就是我们最后要的结果.这个思路的时间复杂度为O(NlogK),空间复杂度为O(K).此方法在海量数据时应用比较好,因为我们的内存有限不能将全部数据读入.
- 下面我只写了方法二的代码,其实两种方法的核心是一致的,稍作改动即可
### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k <= 0 or k > len(arr):
            return []
        heap = self.build_heap(arr[:k])
        print(heap)
        for i in range(k, len(arr)):
            if arr[i] < heap[0]:
                heap[0] = arr[i]
                self.sink(heap, 0)
        return heap

    def sink(self, array, k):
        n = len(array)
        left = 2 * k + 1
        right = 2 * k + 2
        if left >= n: return
        max_i = left 
        if right < n and array[left] < array[right]:
            max_i = right
        if array[max_i] > array[k]:
            array[max_i], array[k] = array[k], array[max_i]
            self.sink(array, max_i)

    def build_heap(self, list_):
        n = len(list_)
        for i in range(n//2, -1, -1):
            self.sink(list_, i)
        return list_







        
        

```