### 解题思路
首先在初始化时对nums降序排序；
在接下来的add()函数中使用二分法查找要插入的元素位置，并插入，而不需要重新排序

时间复杂度要比官方题解1中add()函数每次都要重新排序要快，大致为O(log(n))到O(n)之间

### 代码

```python3
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k=k
        self.nums=nums
        self.nums.sort(reverse=True)

    def add(self, val: int) -> int:
        left=0
        right=len(self.nums)-1
        while left<=right:
            mid=left+(right-left)//2
            if val==self.nums[mid]:
                left=mid
                break
            if val>self.nums[mid]:
                right=mid-1
            else:
                left=mid+1
        self.nums.insert(left,val)
        return self.nums[self.k-1]
        

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```