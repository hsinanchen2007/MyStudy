### 解题思路
两数之和：
1定义类
2在类中定义函数(设置参数)
3利用for循环，先在数组内定位一个数
4根据给出的和，计算另一个数的值，判断其在数组内的位置
5最后返回两数在数组内的索引


### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:(注释输入参数类型)
        for n in range(len(nums)):(先取第一个数的索引)
            number02=target-nums[n](计算第二个数=target-第一个数)
            if number02 in nums:(判断第二个数是否在数组内,若在，则返回索引)
                c=nums.index(number02)(取第二个数的索引)
                if n==c:(判断两个数的索引是否相同,若相同，则跳过循环)
                    continue
                else:
                    return n,c(判断两个数的索引是否相同,若不同，则跳出循环)
                    break
            else:(判断第二个数是否在数组内,若不在，则跳过循环)
                continue

nums = [2, 7, 11, 15]
target = 9

Solution()











```