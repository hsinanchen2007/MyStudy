### 解题思路
这里采用官方题解的思路，先用一次二分查找来找出 pivot 旋转点
利用此旋转点把数组分为两段，然后确定需要在哪一段搜索，最终返回搜索结果。

注意到，查找pivot 使用排除法，这里 if 的条件其实很精细，一定要仔细考虑，连续碰到两次 bug。

if 条件判断最好改为 if nums[mid]>=nums[0], 否则容易遭遇 mid=0 时的bug.
其实 > 变为 >= 有时候更好，更鲁棒


``` python3
a, b = 0, n-1
while a<b:
    mid = a + (b-a)//2
    # if nums[mid] > nums[a]: bug
    #if nums[mid] > nums[0]: bug [3,1]
    if (mid==0) or nums[mid]>nums[0]: # or nums[mid] >= nums[0]
        a = mid+1
    else:
        b = mid
pivot = a
```


### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n==0:
            return -1
        if n==1:
            if nums[0]==target:
                return 0
            else:
                return -1
        if nums[0] > nums[n-1]:  # 已经旋转过
            a, b = 0, n-1
            while a<b:
                mid = a + (b-a)//2
                # if nums[mid] > nums[a]: bug
                #if nums[mid] > nums[0]: bug [3,1]
                if (mid==0) or nums[mid]>nums[0]:
                    a = mid+1
                else:
                    b = mid
            pivot = a

            if nums[0]<=target<=nums[pivot-1]: # pivot不可能为0 
                left, right = 0, pivot-1
            elif nums[pivot]<=target<=nums[n-1]:
                left, right = pivot, n-1
            else:  # 不存在 target
                return -1
        else:
            left, right = 0, n-1

        while left<right:
            mid = (left+right)//2
            if nums[mid]<target:
                left = mid+1
            else:
                right = mid
        if nums[left] == target:
            return left
        else:
            return -1

```