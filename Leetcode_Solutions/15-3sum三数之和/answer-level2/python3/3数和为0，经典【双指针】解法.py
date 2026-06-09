### 解题思路
nums[i]作为最小值，start, end = i+1, n-1开始双指针寻解
剪枝1
if i>0 and nums[i]==nums[i-1]: # 最小值只使用一次
continue
剪枝2
if nums[i]>0: # 最小值大于0，直接跳出
break
剪枝3：
if head>i+1 and nums[head]==nums[head-1]:
    head+=1
    continue
if tail < len(nums)-1 and nums[tail]== nums[tail+1]:
    tail -= 1
    continue


### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        # 固定nums[i]为三者最小值，head, tail = i+1, len(nums)-1 双指针求解
        for i in range(0, len(nums)-2):
            if nums[i]>0: # 最小值大于0的话，往后肯定无解
                break
            if i>0 and nums[i]==nums[i-1]: # 跳过重复值
                continue
            deta = -nums[i]
            head, tail = i+1, len(nums)-1
            while head<tail:
                # 跳过重复值
                if head>i+1 and nums[head]==nums[head-1]:
                    head+=1
                    continue
                if tail < len(nums)-1 and nums[tail]== nums[tail+1]:
                    tail -= 1
                    continue
                # 判断当前组合情况
                tmp = nums[head]+nums[tail]
                if tmp == deta:
                    res.append([nums[i],nums[head], nums[tail]])
                    tail -= 1
                    head += 1
                elif tmp>deta:
                        tail -= 1
                elif tmp<deta:
                        head += 1
        return res
```

