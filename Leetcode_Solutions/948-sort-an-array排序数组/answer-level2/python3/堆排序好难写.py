### 解题思路
利用堆排序完成数组排序

### 代码

```python3
class Solution:
    def swap(self, arr, i, j):
        arr[i], arr[j] = arr[j], arr[i]
    def heapify(self, tree, n, i):
        if i >= n:
            return
        c1 = 2 * i + 1
        c2 = 2 * i + 2
        maxx = i
        if c1 < n and tree[c1] > tree[maxx]:
            maxx = c1
        if c2 < n and tree[c2] > tree[maxx]:
            maxx = c2
        if maxx != i:
            self.swap(tree, maxx, i)
            self.heapify(tree, n, maxx)
    def build_heap(self, tree, n):
        last_node = n - 1
        parent = (last_node - 1) // 2
        for i in range(parent, -1, -1):
            self.heapify(tree, n, i)
    def heap_sort(self, tree, n):
        self.build_heap(tree, n)
        for i in range(n-1, -1, -1):
            self.swap(tree, i, 0)
            self.heapify(tree, i, 0)
    def sortArray(self, nums):
        self.heap_sort(nums,  len(nums))
        return nums
```