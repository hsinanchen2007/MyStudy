这题是对**堆，优先队列**很好的练习，因此有必要自己用python实现研究一下。**堆 处理海量数据的topK，分位数**非常合适，**优先队列**应用在元素优先级排序，比如本题的频率排序非常合适。与基于比较的排序算法 时间复杂度**O(nlogn)** 相比, 使用**堆，优先队列**复杂度可以下降到 **O(nlogk)**,在总体数据规模 n 较大，而维护规模 k 较小时，时间复杂度优化明显。
**堆，优先队列**的本质其实就是个完全二叉树，有其下重要性质
1. 父节点index为 (i-1) // 2
2. 左子节点index为 2*i + 1
3. 右子节点index为 2*i + 2
4. 大顶堆中每个父节点大于子节点，小顶堆每个父节点小于子节点
5. 优先队列以优先级为堆的排序依据
因为性质1，2，3，堆可以用数组直接来表示，不需要通过链表建树。

**堆，优先队列** 有两个重要操作，时间复杂度均是 O(logk)。以大顶锥为例：
1. 上浮sift up: 向堆新加入一个元素，堆规模+1，依次向上与父节点比较，如大于父节点就交换。
2. 下沉sift down: 从堆取出一个元素（堆规模-1，用于堆排序）或者更新堆中一个元素（本题），逆序遍历数组index从 (k-1) // 2 到 index为 0，向下走保证父节点大于子节点。

对于topk 问题：**最大堆求topk小，最小堆求topk大。**
- topk小：构建一个k个数的最大堆，当读取的数小于根节点时，替换根节点，重新塑造最大堆
- topk大：构建一个k个数的最小堆，当读取的数大于根节点时，替换根节点，重新塑造最小堆

**这一题的总体思路** 总体时间复杂度 **O(nlogk)**
- 建立字典遍历一次统计出现频率. O(logn)
- 前k个数构造**规模为k的最小堆** minheap. O(k)
- 遍历规模k之外的数据，大于堆顶则入堆，维护规模为k的最小堆 minheap. O(nlogk)
- (如需按频率输出，对规模为k的堆进行排序)
 
```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # hashmap 统计频率
        freq_count = {}
        for num in nums:
            if num in freq_count:
                freq_count[num] += 1
            else:
                freq_count[num] = 1

        def sift_up(arr, k):
            """ 时间复杂度 O(logk) k 为堆的规模"""
            new_index, new_val = k-1, arr[k-1]
            while (new_index > 0 and arr[(new_index-1)//2][1] > new_val[1]):
                arr[new_index] = arr[(new_index-1)//2]
                new_index = (new_index-1)//2
            arr[new_index] = new_val # 这里采用的是类似插入排序的赋值交换

        def sift_down(arr, root, k):
            """ O(logk). 左节点index 2*root+1, 右节点 2*root+2, 父节点 (child-1)//2"""
            root_val = arr[root]
            while (2*root+1 < k):
                child = 2 * root + 1
                # 小顶锥 用 >，大顶锥 用 <
                if child+1 < k and arr[child][1] > arr[child+1][1]:
                    child += 1
                if root_val[1] > arr[child][1]:
                    arr[root] = arr[child]
                    root = child # 继续向下检查
                else: break # 如果到这里没乱序，不用再检查后续子节点
            arr[root] = root_val

        # 注意构造规模为k的堆, 时间复杂度O(n)，因为堆的规模是从0开始增长的
        freq_list = list(freq_count.items())
        min_heap = []
        for i in range(k):
            min_heap.append(freq_list[i])
            sift_up(min_heap, i+1)

        # 遍历剩下元素，大于堆顶入堆，下沉维护小顶堆
        for item in freq_list[k:]:
            priority = item[1]
            if priority > min_heap[0][1]:
                min_heap[0] = item
                sift_down(min_heap, 0, k)

        return [item[0] for item in min_heap]
``` 

再附上堆排序，其实就是
1. 下沉（堆规模不变），构造大顶锥
2. 下沉（堆规模-1），依次把最大值放到尾部，不再维护。

```python 
def heapSort(arr):
    def sift_down(arr, root, k):
        root_val = arr[root] # 用插入排序的赋值交换
        # 确保交换后，对后续子节点无影响
        while (2*root+1 < k):
            # 构造根节点与左右子节点
            child = 2 * root + 1  # left = 2 * i + 1, right = 2 * i + 2
            if child+1 < k and arr[child] < arr[child+1]: # 如果右子节点在范围内且大于左节点
                child += 1
            if root_val < arr[child]:
                arr[root] = arr[child]
                root = child
            else: break # 如果有序，后续子节点就不用再检查了
        arr[root] = root_val

    k = len(arr) # k 为heap的规模
    # 构造 maxheap. 从倒数第二层起，该元素下沉
    for i in range((k-1)//2, -1, -1):
        sift_down(arr, i, k)
    # 从尾部起，依次与顶点交换并再构造 maxheap，heap规模-1
    for i in range(k - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # 交换
        sift_down(arr, 0, i)
```