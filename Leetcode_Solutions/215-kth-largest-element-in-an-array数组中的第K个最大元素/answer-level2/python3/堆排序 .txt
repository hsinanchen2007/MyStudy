### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/d2041dbfe58cae24130e300a1933481e61df8cefd2b243a01e7c98d31ebb78ce-image.png)
自己写的堆排序，得分还行吧

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def heapsort(arr,start,end):
            root = start
            while True:
                i = 2*root+1
                if i >end:
                    break
                if i+1<end and arr[i+1]<arr[i]:
                    i += 1
                if i<end and arr[i]<arr[root]:
                    arr[root],arr[i] = arr[i],arr[root]
                    root = i
                else:
                    break



        res = nums[:k]
        for i in range(k//2-1,-1,-1):
            heapsort(res,i,k)
        for i in range(k,len(nums)):
            if nums[i]>res[0]:
                res[0] = nums[i]
                heapsort(res,0,k)
        return res[0]
```