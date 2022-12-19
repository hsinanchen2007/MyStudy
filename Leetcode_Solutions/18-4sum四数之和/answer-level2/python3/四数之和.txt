### 题目分析
1、判断题目类型：数组类型
2、解决关键：数组指针（左右指针）
3、考虑边界值：
第一种情况：左指针+右指针<目标点
第二种情况：左指针+右指针>目标点
第三种情况：重复
左指针-1和左指针相等
右指针和右指针+1相等
这个和求三数之和相比需要注意的是这个传入的参数是两个，有一个nums和target,target不一定是0，而三数之和传入的参数只有nums一个，求总和为0

### 代码
````
class Solution():
    def fourSum(self, nums,target):
        res = []
        nums.sort()
        for i in range(0, len(nums) - 3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, len(nums) - 2):
                if j >i+1 and nums[j] == nums[j - 1]:
                    continue
                start, end = j + 1, len(nums) - 1                               
                while start < end:
                    all = nums[start]+nums[end]+nums[i]+nums[j]
                    # 第一种情况
                    if all > target:
                        end -= 1
                    # 第二种情况
                    elif all < target :
                        start += 1
                    else:
                        res.append((nums[i], nums[j], nums[start], nums[end]))
                        end -= 1
                        start += 1
                        # 第三种情况
                        while start < end and nums[end] == nums[end + 1]:
                            end -= 1
                        while start < end and nums[start] == nums[start - 1]:
                            start += 1
        return res

````
