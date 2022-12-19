### 解题思路
归并排序的过程中统计逆序数

### 代码

```python3
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def mergeSort(left, right):
            if left >= right: return 0
            mid = (left + right) // 2
            count = mergeSort(left, mid) + mergeSort(mid+1, right)
            count += merge(left, mid, right)
            return count
        
        def merge(left, mid, right):
            p1, p2 = left, mid + 1
            temp = []
            count = 0  # 逆序对数
            while p1 <= mid and p2 <= right:
                if nums[p1] <= nums[p2]:
                    temp.append(nums[p1])
                    p1 += 1
                else:  # 出现逆序对
                    temp.append(nums[p2])
                    p2 += 1
                    count += mid - p1 + 1
            while p1 <= mid:
                temp.append(nums[p1])
                p1 += 1
            while p2 <= right:
                temp.append(nums[p2])
                p2 += 1
            nums[left:left+len(temp)] = temp
            return count
        res = mergeSort(0, len(nums)-1)
        return res
```