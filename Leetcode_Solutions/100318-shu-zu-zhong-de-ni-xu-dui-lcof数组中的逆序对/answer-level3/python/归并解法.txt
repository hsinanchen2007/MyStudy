一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
暴力法时间复杂度是o(n^2)，超时。

考虑一下，逆序是说a[i]>a[j]，i<j。那么在排序的过程中，会把a[i]和a[j]交换过来，这个交换的过程，每交换一次，就是一个逆序对的“正序”过程。

排序每个数，归并排序。

### 代码

```python
def MergeElem(data, start, mid, end, temp):  # data[start...mid], data[mid+1...end]
    cnt = 0
    i = start
    j = mid + 1
    k = start
    while i <= mid and j <= end:
        if data[j] < data[i]:  # data[start...i...mid] data[mid+1...j...end]
            temp[k] = data[j]
            cnt += j - k
            j += 1
            k += 1
        else:
            temp[k] = data[i]
            i += 1
            k += 1
    while i <= mid:
        temp[k] = data[i]
        i += 1
        k += 1
    while j <= end:
        temp[k] = data[j]
        j += 1
        k += 1
    data[start:end+1] = temp[start:end+1]
    return cnt

def InverseCore(data, start, end, temp):
    cnt = 0
    if start < end:
        mid = (start + end) // 2
        cnt += InverseCore(data, start, mid, temp)
        cnt += InverseCore(data, mid+1, end, temp)
        cnt += MergeElem(data, start, mid, end, temp)
    return cnt

class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp = nums[:]
        count = InverseCore(nums, 0, len(nums)-1, temp)
        return count
```