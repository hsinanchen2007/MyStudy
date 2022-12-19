非比较排序适用于数量远多于数值范围的情形，本题限定数值范围，亦可完成数组排序。（懒得写了）

快速排序，堆排序，归并排序，希尔排序，Python3完整实现代码如下所示。

欢迎各位大佬指点

```python3
from typing import List
import random
class Solution:
    # 快速排序
    def sortArray(self, nums: List[int]) -> List[int]:
        def quickSort(arr, left, right):
            if right - left <= 0:
                return
            # random update
            random_index = random.randint(left, right)  # in range [a, b]
            swap(arr, random_index, right)

            equal_left, equal_right = partition(arr, left, right)
            quickSort(arr, left, equal_left - 1)
            quickSort(arr, equal_right + 1, right)

        def partition(arr, left, right):
            # netherlands flag update
            # less, more both inclusive
            less = left - 1
            more = right
            num = arr[right]

            # print('init arr', arr)
            i = left
            while i < more:
                if arr[i] < num:
                    less += 1
                    swap(arr, i, less)
                    i += 1
                    # print('less swap arr', arr)
                elif arr[i] > num:
                    more -= 1
                    swap(arr, i, more)
                    # print('more swap arr', arr)
                else:
                    i += 1
                    # print('still arr', arr)
            # print('before swap arr', arr)
            swap(arr, more, right)
            more += 1
            # print('after swap arr', arr)
            return [less + 1, more - 1]

        def swap(arr, i, j):
            if i != j and abs(i - j) != len(arr):
                arr[i] ^= arr[j]
                arr[j] ^= arr[i]
                arr[i] ^= arr[j]

        arr = nums
        if arr == None or len(arr) < 2:
            return arr
        quickSort(arr, 0, len(arr) - 1)
        return arr

    # 堆排序
    def sortArray(self, nums: List[int]) -> List[int]:
        # 大根堆插入，保持大根堆
        def insert_heap(arr, index):
            parent = (index - 1) >> 1 if index > 0 else 0
            while arr[index] > arr[parent]:
                swap(arr, index, parent)
                index = parent
                parent = (index - 1) >> 1 if index > 0 else 0

        # 弹出大根堆顶部（最大值），然后调整大根堆
        def heapify(arr, index, size):
            left = index * 2 + 1
            while left < size:
                if arr[left] > arr[index]:
                    if left + 1 < size and arr[left + 1] > arr[left]:
                        swap(arr, index, left + 1)
                        index = left + 1
                    else:
                        swap(arr, index, left)
                        index = left
                elif left + 1 < size and arr[left + 1] > arr[index]:
                    swap(arr, index, left + 1)
                    index = left + 1
                else:
                    break
                left = index * 2 + 1

        def swap(arr, i, j):
            if i != j and abs(i - j) != len(arr):
                arr[i] ^= arr[j]
                arr[j] ^= arr[i]
                arr[i] ^= arr[j]

        arr = nums
        if arr == None or len(arr) < 2:
            return arr
        size = len(arr)
        # 构建大根堆
        for i in range(size):
            insert_heap(arr, i)
        # 弹出大根堆顶部，调整大根堆
        for i in range(size):
            swap(arr, 0, size - 1 - i)
            heapify(arr, 0, size - 1 - i)
        return arr

    # 归并排序
    def sortArray(self, nums: List[int]) -> List[int]:
        def mergeSort(arr, l, r):
            if l == r:
                return
            mid = l + ((r - l) >> 1)
            mergeSort(arr, l, mid)
            mergeSort(arr, mid + 1, r)
            merge(arr, l, mid, r)

        def merge(arr, l, mid, r):
            help_arr = [0 for i in range(r - l + 1)]
            i = l
            j = mid + 1
            k = 0
            while i <= mid and j <= r:
                if arr[i] < arr[j]:
                    help_arr[k] = arr[i]
                    i += 1
                    k += 1
                elif arr[i] == arr[j]:
                    help_arr[k] = arr[i]
                    i += 1
                    k += 1
                else:
                    help_arr[k] = arr[j]
                    j += 1
                    k += 1
            while i <= mid:
                help_arr[k] = arr[i]
                i += 1
                k += 1
            while j <= r:
                help_arr[k] = arr[j]
                j += 1
                k += 1
            for i, ele in enumerate(help_arr):
                arr[l + i] = ele

        arr = nums
        if arr is None or len(arr) < 2:
            return arr
        mergeSort(arr, 0, len(arr) - 1)
        return arr

    # 希尔排序
    def sortArray(self, nums: List[int]) -> List[int]:
        def swap(arr, i, j):
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp

        arr = nums
        gap = len(arr) // 2
        while gap >= 1:
            for i in range(gap, len(arr)):
                j = i
                while j - gap >= 0 and arr[j - gap] > arr[j]:
                    swap(arr, j - gap, j)
                    j -= gap
            gap = gap // 2
        return arr

```