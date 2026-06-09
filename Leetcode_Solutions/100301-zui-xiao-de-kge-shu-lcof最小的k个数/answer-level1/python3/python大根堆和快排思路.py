### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k<= 0:return []
        #大根堆
        def heapify(tree,n,i):
            c1 = 2*i + 1
            c2 = 2*i + 2
            max = i
            if c1 < n and tree[max] < tree[c1]:
                max = c1
            if c2 < n and tree[max] < tree[c2]:
                max = c2
            if max != i:
                tree[i],tree[max] = tree[max],tree[i]
                heapify(tree,n,max)
        def build_heap(tree,n):
            last_node = n-1
            parent = last_node//2
            for i in range(parent,-1,-1):
                heapify(tree,n,i)
            return tree
        
        heap = build_heap(arr[:k],k)
        for i in range(k,len(arr)):
            if arr[i] < heap[0]:
                heap[0] = arr[i]
                heapify(heap,k,0)
        return heap

        '''
        #快排
        if k > len(arr) or k <= 0:
            return []
        def partition(arr,start,end):
            low = start
            high = end
            temp = arr[low]
            while low < high:
                while low < high and arr[high] >= temp: #先从high 开始
                    high -= 1
                arr[low] = arr[high]
                while low < high and arr[low] < temp:
                    low += 1
                arr[high] = arr[low]

            arr[low] = temp
            return low

        start = 0
        end = len(arr) - 1
        index = partition(arr,start,end)
        while index != k-1:
            if index > k-1:
                end = index-1
                index = partition(arr,start,end)
            if index < k-1:
                start = index + 1
                index = partition(arr,start,end)
        return arr[:k]
        '''
        '''
        #堆排序
        def heapify(tree,n,i):
            if i >=n:
                return
            c1 = 2 * i + 1
            c2 = 2 * i + 2
            max = i
            if c1 < n and tree[max] > tree[c1]:
                max = c1
            if c2 < n and tree[max] > tree[c2]:
                max = c2
            if max != i:
                tree[max],tree[i] = tree[i],tree[max]
                heapify(tree,n,max)
        def build_heap(tree,n):
            last_node = n - 1
            parent = last_node//2
            for i in range(parent,-1,-1):
                heapify(tree,n,i)
        def heap_sort(tree,n):
            build_heap(tree,n)
            for i in range(n-1,-1,-1):
                tree[0],tree[i] = tree[i],tree[0]
                heapify(tree,i,0)
        
        n = len(arr)
        ans = []
        build_heap(arr,n)
        for i in range(n-1,n-1-k,-1):
            ans.append(arr[0])
            arr[0],arr[i] = arr[i],arr[0]
            heapify(arr,i,0)
    
        return ans
        '''
```