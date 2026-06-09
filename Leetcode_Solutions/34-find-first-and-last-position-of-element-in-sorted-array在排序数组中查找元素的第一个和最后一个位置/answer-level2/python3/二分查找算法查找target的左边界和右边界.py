**二分查找到target之后，在此位置向前搜索看还有没有target，在此位置向后搜索看还有没有target**
**虽然这种方法能得到正确结果，但若数组中有多个值都和target相等，则可能导致O(n)**

```
class Solution:  # 二分查找 加 前后搜索
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums)-1
        while r >= l:
            mid = (l+r) >> 1
            if nums[mid] == target:
                temp_mid = mid
                while mid-1 >=0 and nums[mid-1] == target:  # mid的位置向前搜索
                    mid -= 1
                while temp_mid+1 < len(nums) and nums[temp_mid+1] == target:  # mid的位置向后搜素
                    temp_mid += 1
                return [mid, temp_mid]
            elif nums[mid] < target:
                l = mid +1
            else:
                r = mid -1
        return [-1, -1]
```


**微微改变二分查找，使其能查找target的边界
先查找左边界，若没有左边界则直接返回[-1, -1]
查找到左边界后，用nums[左边界+1:]这部分再接着查找右边界，范围已经缩小了，时间更快**
```
class Solution:  # 二分查找
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums)-1
        res = []
        while l <= r:  # 寻找左边界
            mid = (l+r) >> 1
            if nums[mid] == target:
                r = mid - 1
            elif nums[mid] > target:
                r = mid - 1
            elif nums[mid] < target:
                l = mid + 1
        if l == len(nums) or nums[l] != target: # l==0表示target小于nums中的所有值但是这种情况可以通过nums[l] != target来判断；l==len(nums)表示target大于nums中的所有值，不能通过nums[l]来判断，索引溢出了；nums[l] != target还可以用来判断target既不完全小于也不完全大于nums并且不在nums中的这种情况，如nums = [3,5,6], targeta = 4
            return [-1, -1]
        res.append(l)  # 找到左边界

        l += 1 # l是target在nums中的左边界，此时l已经确认是target了，所以给它加1处理后面的那部分数组
        r = len(nums)-1  # 此时右边界是等于l-1的，所以这里重新赋值
        while l <= r:  # 寻找右边界
            mid = (l+r) >> 1
            if nums[mid] == target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
        res.append(l-1)  # 寻找右边界时不管nums的后半部分有没有target, l都会停留在target最后出现的位置的下一个位置
        return res
```
