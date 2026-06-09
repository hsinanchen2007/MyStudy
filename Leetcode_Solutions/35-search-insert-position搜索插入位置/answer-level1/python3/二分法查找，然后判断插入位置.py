### 解题思路
此处撰写解题思路
因为给的数组是有序的，用二分法查找很快。只要1-log2(n)次既可以找出target的位置。
初始化两个指针，头尾指针
begin = 0, end = len(nums)-1
中间:middle = int((begin+end)/2)
if nums[middle] == target:
    return middle
elif target >nums[middle]:
    begin = middle
else:
    end = middle
循环更改middle值和判断
### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums:
            nums.append(nums)
            return 0
        begin =0
        end =len(nums)-1
        while begin+1<end:
            middle = int((begin+end)/2)
            if nums[middle] == target:
                return middle
            elif target > nums[middle]:
                begin = middle
            else:
                end = middle
        if target < nums[begin]:
            rs = max(begin-1, 0)
            nums.insert(rs, target)
            return rs
        elif target == nums[begin]:
            return begin
        elif target == nums[end]:
            return end
        elif target >nums[end]:
            nums.insert(end+1, target)
            return end+1
        else:
            nums.insert(begin+1, target)
            return begin+1
```