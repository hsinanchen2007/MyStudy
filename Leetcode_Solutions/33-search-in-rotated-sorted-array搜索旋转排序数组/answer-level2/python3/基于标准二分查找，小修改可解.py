### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def __init__(self):
        self.ans = -1
    def search(self, nums: List[int], target: int) -> int:
        def bisearch(head, tail):
            # 1. 判断边界
            if head>tail: return
            # 2. 获取mid，并判断mid是否相等
            mid = (head+tail)//2 
            if nums[mid]== target:
                self.ans = mid
                return
            # 3. 不相等时，选择一侧继续递归二分
            elif tail>head: # 不想等时，tail>head 才有继续二分的必要
                # 纯升序list
                if nums[tail]>nums[head]: 
                    if nums[mid]<target:  # 选择具体哪一边递归
                        bisearch(mid+1, tail)
                    else:
                        bisearch(head, mid-1)
                # 非纯升序列，两边都需要进一步递归（此处以上是标准二分查找）
                else:
                    bisearch(head, mid-1)
                    bisearch(mid+1, tail)
        bisearch(0, len(nums)-1)
        return self.ans

            

```
时间复杂度O(logn)
空间复杂度O(1)