### 解题思路
快速排序每次会确定一个元素的位置，这个元素的左边都小于它，右边都大于它。
所以只需要判断这个元素的索引与k-1的大小关系。
若等于，则数组当前的前k个数即最小k，返回。
若大于，说明最小k在前半部分，所以继续快排前半部分。
若小于，说明最小k在后半部分，所以继续快排后半部分。

### 代码

```python3
class Solution:
    def quick_K(self, arr, left, right, k):
        if left >= right:
            return
        low = left
        high = right
        key = arr[low]
        while left < right:
            while left < right and arr[right] > key:
                right -= 1
            arr[left] = arr[right]
            while left < right and arr[left] <= key:
                left += 1
            arr[right] = arr[left]
        arr[right] = key
        if right==k:
            return
        elif right<k:
            self.quick_K(arr, left + 1, high, k)
        else:
            self.quick_K(arr, low, left - 1, k)

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        
        self.quick_K(arr, 0, len(arr)-1, k-1)
        return arr[:k]
```