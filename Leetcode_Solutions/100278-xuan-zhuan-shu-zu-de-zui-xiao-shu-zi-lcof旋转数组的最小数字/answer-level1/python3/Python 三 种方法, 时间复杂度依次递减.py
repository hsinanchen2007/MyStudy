### 方法一: 时间复杂度 O(NlogN) 
粗暴的排序,然后返回第一个元素

```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if not numbers: return None
        numbers.sort()
        return numbers[0]
```

### 方法二: 时间复杂度 O(N).
对于一个完全升序的序列,后一个数字一定大于等于前一个,那么如果出现后一个数字小于前一个, 则这个后一个数字一定是最小的; 如果循环结束仍没找到这个数字, 说明该序列是从第一个元素整体旋转了,也就是其还是原来的序列,直接返回第一个元素.

```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if not numbers: return None
        for i in range(1, len(numbers)):
            if numbers[i] < numbers[i-1]:
                return numbers[i]
        return numbers[0]
```
### 方法三: 二分法 O(logN). 
设置左右指针, 如果中间元素小于最右边元素, 说明中间元素位于最小元素的右边, 故,将 right=mid, 区间向左缩; 如果中间元素大于最右元素, 说明中间元素在最小元素的左边, 故将左边的边界缩到中间的下一个(因为中间元素大于最右元素, 故其绝对不是最小元素), left=mid+1; 若中间元素等于最右元素, 右指针减1, 因为其要么不是最小, 要么即使最小, 也和中间元素重复,保留中间元素即可.

```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if not numbers: return None
        left = 0
        right = len(numbers)-1
        while left < right:
            mid = (left+right) // 2
            if numbers[mid] < numbers[right]:
                right = mid
            elif numbers[mid] > numbers[right]:
                left = mid + 1
            elif numbers[mid] == numbers[right]:
                right -= 1
        return numbers[left]
```