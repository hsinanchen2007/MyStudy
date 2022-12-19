### 解题思路
python hash + 堆排序
注意要将Dictionary类型转化为list类型，并且比较的是list中每个元素的第二位
### 代码

```python
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        h = {}
        n = len(nums)
        for i in range(0,n):
            if nums[i] in h:
                h[nums[i]] += 1
            else:
                h[nums[i]] = 1
        arr = list(h.items())
        #print(arr)
        
        def heapify(h,n,i):
            smallest = i
            left = 2*i+1
            right = 2*i+2
            if left < n and h[left][1] < h[smallest][1]:
                smallest = left
            if right < n and h[right][1] < h[smallest][1]:
                smallest = right
            if smallest != i:
                h[i],h[smallest] = h[smallest], h[i]
                heapify(h,n,smallest)
        
        for i in range(len(arr),-1,-1):
            heapify(arr,len(arr),i)
        for i in range(len(arr)-1,0,-1):
            arr[i], arr[0] = arr[0], arr[i]
            heapify(arr, i, 0)
        #print(arr)
        ans =[]
        for i in range(0,k):
            ans.append(arr[i][0])

        return ans



```