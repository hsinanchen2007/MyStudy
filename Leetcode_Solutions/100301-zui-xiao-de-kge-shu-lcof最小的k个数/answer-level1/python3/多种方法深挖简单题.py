### 解题思路
最弱智的当然是直接排序，接着我们可以想到用堆排序，可以直接调用函数或者是我们手动加入这个维护k个大根堆的算法

更进阶一点可以用到快速选择算法，这里比较坑的就是corner case的考虑，因为返回的是一个范围，末尾值可能会落在l，r之外
所以落在r右边一个位置的时候可以通过修改判断语句来修正
落在左边，也就是k为0的时候可以单独打一个补丁

听说更高级的还有一个BFPRT算法，有点烦，暂时先不写了

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 直接调用快排
        # arr.sort()
        # return arr[:k]
        
        # 直接调用堆排序
#         heapq.heapify(arr)
#         ans = []
#         for i in range(k):
#             tmp = heapq.heappop(arr)
#             ans.append(tmp)
        
#         return ans
        # 可以动态地堆排序来减少插入次数，想法是做一个大根堆，然后用一个判断去决定是否把数字插入
        # 在python中默认小根堆，所以需要把数字取相反数来实现
#         if k == 0:
#             return []

#         hp = [-x for x in arr[:k]]
#         heapq.heapify(hp)
#         for i in range(k, len(arr)):
#             if -hp[0] > arr[i]:
#                 heapq.heappop(hp)
#                 heapq.heappush(hp, -arr[i])
#         ans = [-x for x in hp]
#         return ans
        
        # 更骚的一行实现
        # return heapq.nsmallest(k, arr)
        
        # 快速选择
        def partition(l,r,pivot_index):
            arr[pivot_index],arr[r] = arr[r],arr[pivot_index]
            pivot = arr[r]
            index = l
            for i in range(l,r):
                if arr[i] < pivot:
                    arr[i],arr[index] = arr[index],arr[i]
                    index += 1
            arr[index], arr[r] = arr[r],arr[index]
            
            return index
            
            
            
        def select(l,r,k):
            if k == 0:
                return []
            pivot_index = random.randint(l,r)
            index = partition(l,r,pivot_index)
            
            if index == k-1:
                return arr[:k]
            elif index > k-1:
                return select(l,index-1,k)
            else:
                return select(index+1,r,k)
            
        return select(0,len(arr)-1,k)
        
                    
        
```