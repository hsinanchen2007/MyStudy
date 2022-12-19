### 解题思路
根据以下分析，二分查找和优先队列哪个好是视情况而定，这个问题中py跑出来结果不相上下，但二分的代码复杂多了。
（「乘法表中第k小的数」 这个问题就是二分占优势）

>优先队列方法时间复杂度约等于`O(klog(min(k, max(m, n))))`  {小根堆的大小不会超过min(k, max(m, n))},
>二分法找到第k个的时间复杂度为`O((m+n)log(Mmax+Nmax-Mmin-Nmin))`

### 代码
**二分法**
先二分查找出排序在第k位的和，再遍历得到小于等于这个和的组合。
```python3
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        if nums1==[] or nums2==[]: return []
        # 找出和为n的排列序号，复杂度O(m+n)，考虑到二分本身不在乎真实值，所以一旦order>k就直接返回得了
        def findOrder(n):
            order=1
            last = len(nums2)
            for v1 in nums1:
                for v2 in reversed(nums2[:last]):
                    if v1+v2<n:
                        order+=last
                        if order>k:
                            return order
                        break
                    else:
                        last-=1
                else:
                    break
            return order

        def getSmallerThanN(n):
            res=[]
            last = len(nums2)
            temp=[]
            for v1 in nums1:
                if len(res)==k:
                    break
                for j, v2 in enumerate(nums2[:last]):
                    if v1+v2<n:
                        res.append([v1,v2])
                    elif v1+v2==n:
                        temp.append([v1,v2])
                    else:                        
                        last = j
                        break  
            if temp!=[]:
                res+=temp
                res=res[:k]       
            return res   

        l = nums1[0]+nums2[0]
        r = nums1[-1]+nums2[-1]+1
        while l<r-1:
            mid = l+(r-l)//2
            order = findOrder(mid)
            if order<=k:
                l=mid
            else:
                r=mid
            
        return getSmallerThanN(l)[:k]    
```
**优先队列**
这个之前的题解就有，过程分析得更为详细，也附上作为参考
```
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        ans=[]
        heap=[]

        def push(i, j):
            if i<len(nums1) and j< len(nums2):
                heapq.heappush(heap, [ nums1[i]+nums2[j], i, j ])
        push(0,0)
        while heap and len(ans)<k:
            _, x, y = heapq.heappop(heap) 
            ans.append([nums1[x], nums2[y]])
            push(x,y+1)
            if y==0:
                push(x+1, y)
              
        return ans 
```
