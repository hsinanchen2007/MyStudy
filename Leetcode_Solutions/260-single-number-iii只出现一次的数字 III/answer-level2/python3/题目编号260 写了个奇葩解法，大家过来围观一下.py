### 解题思路
先对列表进行升序或者降序排列，然后从起始位置判断相邻元素是否相等，第一个不相等元素即符合条件，接着继续比较下一位相邻元素，以此类推
python3 执行用时 :68 ms，内存消耗 :14.4 MB
### 代码
```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        # 升序排列
        nums.sort()
        count = 0
        i = 3
        j = 3
        k = 2
        # nums长度为2直接输出
        if len(nums) == 2:
            return nums
        # 判断前两个元素是否相等，不相等则nums[0]第一个符合条件
        elif nums[0] != nums[1]:
            if nums[1] == nums[2]:
                # 说明第二个符合条件的元素在末尾
                if nums[-1] != nums[-2]:
                    return [nums[0],nums[-1]]
                # 说明第二个个符合元素在中间，需要遍历
                else:
                    while True:
                        if nums[j] == nums[j+1]:
                            j += 2
                        else:
                            return [nums[0], nums[j]]
            # 若nums[1]与nums[2]不相等，则nums[0], nums[1]符合条件
            else:
                return [nums[0], nums[1]]
        # 说明符合的元素不在开头位置
        else:
            # 说明第一个符合条件的元素在末尾
            if nums[-1] != nums[-2]:
                # 说明第二个符合条件的元素在倒数第二位
                if nums[-2] != nums[-3]:
                    return [nums[-2], nums[-1]]
                # 说明第二个符合条件的元素在中间
                else:
                    while True:
                        if nums[i] == nums[i+1]:
                            i += 2
                        else:
                            return [nums[i], nums[-1]]
            # 符合条件的两个元素均在中间位置
            else:
                while True:
                    if nums[k] == nums[k+1]:
                        k += 2
                    else:
                        count += 1
                        if count ==2:
                            return [a, nums[k]]
                        a = nums[k]
                        k += 1


                
            

```