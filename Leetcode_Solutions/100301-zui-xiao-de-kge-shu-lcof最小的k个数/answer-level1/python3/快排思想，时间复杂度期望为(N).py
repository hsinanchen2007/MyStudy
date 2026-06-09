### 解题思路
此处撰写解题思路

### 代码

```python3
import heapq
import random
class Solution1:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 堆排 O(NlogK)
        # 大根堆解决前K小，小根堆解决前K大
        if k == 0:
            return []
        # python中默认是小根堆，需要先将数组元素变为相反数
        hp = [-i for i in arr[:k]]
        heapq.heapify(hp)
        for i in range(k, len(arr)):
            if -hp[0] > arr[i]:
                heapq.heappop(hp)
                heapq.heappush(hp, -arr[i])
        res = [-x for x in hp]
        return res
# -----------------------
# -----------------------
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        # 快排的思想
        def partition(left, right, target):
            index = arr[target]
            arr[left], arr[target] = arr[target], arr[left]
            # 挖坑法
            while left < right:
                while left < right and arr[right] >= index:
                    right -= 1
                arr[left] = arr[right]
                while left < right and arr[left] <= index:
                    left += 1
                arr[right] = arr[left]
            arr[left] = index
            return left
        def partition1(left, right, target):
            index = arr[target]
            arr[left], arr[target] = arr[target], arr[left]
            k  = left
            # 指针交换法
            while left < right and arr[right] >= target:
                right -= 1
            while left < right and arr[left] <= target:
                left += 1
            if left < right:
                arr[left], arr[right] = arr[right], arr[left]
            arr[left], arr[k] = arr[k], arr[left]
            return left
        def select(left, right):
            pivot = random.randint(left, right)
            index = partition(left, right, pivot)
            if index > k:
                select(left, index - 1)
            elif index < k:
                select(index + 1, right)
        if k == 0:
            return []
        if k == n:
            return arr[:k]
        k = k - 1
        select(0, n - 1)
        return arr[:k+1]
```