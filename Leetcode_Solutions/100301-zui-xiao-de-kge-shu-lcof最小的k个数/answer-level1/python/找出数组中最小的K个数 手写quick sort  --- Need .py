### 解题思路
1. 两种思路非常明确：O（NlogN）
    - **最大堆，有元素比堆顶小，替换并调整堆**
    - **partion 思想**
2. **漏洞百出，调试出了4处错误，这值得深思**
    - 当然需要总结模板了
    - **边界控制问题， error3  error 4 **
    - **error 1 2 其实书写代码习惯不好造成的**。

3. 快排思想的空间、时间复杂度分析：
    - **时间复杂度：期望为 O(n）** ，由于证明过程很繁琐，所以不再这里展开讲。具体证明可以参考《算法导论》第 9 章第 2 小节。
        - **最坏情况下的时间复杂度为 O(n^2)**。情况最差时，每次的划分点都是最大值或最小值，一共需要划分 n - 1次，而一次划分需要线性的时间复杂度，所以最坏情况下时间复杂度为 O(n^2)。
    - **空间复杂度：期望为 O(log n)**，**递归调用的期望深度为 O(log n)，**每层需要的空间为 O(1)，只有常数个变量。
        - **最坏情况下的空间复杂度为 O(n)**。最坏情况下需要划分 n次，即 randomized_selected 函数递归调用最深 n - 1 层，而每层由于需要 O(1)的空间，所以一共需要 O(n)的空间复杂度。

4. 方法二：堆 空间、时间复杂度
    - **时间复杂度：O(nlogk)**，其中 n是数组 arr 的长度。由于大根堆实时维护前 k小值，所以插入删除都是 O(logk) 的时间复杂度，最坏情况下数组里 n个数都会插入，所以一共需要 O(nlogk) 的时间复杂度。
    - **空间复杂度：O(k)**，因为大根堆里最多 k个数

5. [Python标准库模块之heapq](https://www.jianshu.com/p/801318c77ab5)
    - 最大堆中父节点 是 最大值  --- 最小堆父节点 是 最小值；因此求前k个最小值: 
        - 1) **应该采用 k个元素（arr[:k]）的最大堆; **
        - 2) **并遍历arr[k:] ,小于堆顶，交换。**
    - **heapq 只支持最小堆，因此把元素取负，就是”最大堆”**
    - heapq有两种方式创建堆：
        - 一种是使用一个空列表，然后使用**heapq.heappush()函数把值加入堆中**
        - 另外一种就是使用**heap.heapify(list)转换列表成为堆结构**
        - 堆创建好后，可以通过`heapq.heappop() 函数弹出堆中最小值








### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 最大堆，有元素比堆顶小，替换并调整堆
        # partion 思想

        nsize = len(arr)
        if nsize < k:
            return arr 
        
        if nsize < 1 or k < 1:
            return []
        
        self.qsort(arr, k, 0, nsize -1)

        return arr[:k]
    
    def qsort(self, arr, k, low, high):
        if low >= high:  ## error 1: low <= high  
            return 
        
        mid = self.partion(arr, k, low, high)

        if mid < k:  ## error 2: low < k; low >k 代码迁移导致
            self.qsort(arr, k, mid+1, high)
        elif mid > k:
            self.qsort(arr, k, low, mid-1)
        else:
            return 
            

    def partion(self, arr, k, low, high):
        par = arr[low]
        while low < high:
            while low < high and arr[high] >= par: ## error 3 : arr[high]>par 和 arr[low] < par 无等号，导致进入死循环
                high -= 1
            arr[low] = arr[high]
            while low < high and arr[low] <= par:
                low += 1
            arr[high] = arr[low]  ## error 4: low <= high，导致越界
        
        arr[low] = par 
        return low 

```

## heap 操作
```
import heapq 
class Solution:
    
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        nsize = len(arr)
        if nsize < k:
            return arr 
        
        if nsize < 1 or k < 1:
            return []
        
        hq = [-x for x in arr[:k]]
        heapq.heapify(hq)
        for i in range(k, nsize):
            if -hq[0] > arr[i]:
                heapq.heappop(hq)
                heapq.heappush(hq, -arr[i])
        
        ans = [-x for x in hq]

        return ans 

```






