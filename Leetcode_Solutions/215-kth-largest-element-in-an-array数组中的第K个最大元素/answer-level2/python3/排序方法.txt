### 解题思路
使用选择排序和插入排序以及冒泡排序是不可以的，因为时间复杂度是O(n^2),所以需要使用高级排序方法，其实步骤很简单
1. 使用归并排序排序
2. 输出倒数第k位

### 代码

```python3
def merge_sort(num):
        if len(num) <= 1:
            return num
        mid = int(len(num) / 2)
        llist, rlist = merge_sort(num[:mid]), merge_sort(num[mid:])
        result = []
        i, j = 0, 0
        while i < len(llist)  and j < len(rlist):
            if rlist[j] < llist[i]:
                result.append(rlist[j])
                j += 1
            else:
                result.append(llist[i])
                i += 1
        result +=   llist[i:] + rlist[j:]
        return result
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        num = merge_sort(nums)
        return num[::-1][k-1]

    

    
        
```