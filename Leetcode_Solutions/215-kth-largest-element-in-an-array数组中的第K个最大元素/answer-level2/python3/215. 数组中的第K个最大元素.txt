### 解题思路
这类题并不要求把所有的数都排好序，所有堆排序非常适合。堆排序的步骤：1.创建堆；2.调整堆。其中调整堆是最基本的操作。

### 代码

```python3
class Solution:
    def findKthLargest(self, nums, k: int) -> int:
        # 最大堆：创建堆、调整堆
        def createHeap(data, end):
            begin = (end - 1) // 2
            for i in range(begin, -1, -1):
                adjustHeap(nums, i, end)

        def adjustHeap(data, start, end):
            cur = start
            while cur <= end:
                # 交换元素
                leftChild = cur * 2 + 1
                rightChild = cur * 2 + 2
                if rightChild <= end:  # 左右子结点都存在
                    if data[rightChild] >= data[leftChild] and data[rightChild] > data[cur]:  # 右子结点比左子结点还有根结点都要大
                        data[cur], data[rightChild] = data[rightChild], data[cur]
                        cur = cur * 2 + 2
                    elif data[leftChild] >= data[rightChild] and data[leftChild] > data[cur]:  # 左子结点最大
                        data[cur], data[leftChild] = data[leftChild], data[cur]
                        cur = cur * 2 + 1
                    else:
                        break
                elif leftChild <= end and data[cur] < data[leftChild]:  # 只左子结点存在
                    data[cur], data[leftChild] = data[leftChild], data[cur]
                    cur = cur * 2 + 1
                else:
                    break

        length = len(nums)
        createHeap(nums, length - 1)
        # 取第k个最大元素
        for i in range(1, k):
            # 交换元素
            nums[0], nums[length - i] = nums[length - i], nums[0]
            # 调整堆
            adjustHeap(nums, 0, length - 1 - i)
        return nums[0]
```