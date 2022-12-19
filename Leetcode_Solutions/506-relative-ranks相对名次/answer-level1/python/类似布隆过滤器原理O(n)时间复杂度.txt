
#### 文字比较枯燥，我们来看下一个实例吧。
假设原始数组 `nums = [1,5,10,6,2,8]`
可以很轻松就能获取到最大的分值是10，所以我们申请一个数组nums_index，元素全是-1，长度为11（即：max+1）
`nums_index = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]`
接下来我们操作nums_index，把原始数组nums里每个元素的值当做nums_index的下标，并把该下标处的值置为原始数组的下标。额...有点绕，继续往下看就明白了。
操作完后的nums_index长这样
`nums_index = [0, -1, 4, -1, -1, 1, 3, -1, 5, -1, 2]`
解释下nums_index，我们从最后面往前看≥0的值
1. 第一名在原始数组下标2的位置
2. 第二名在原始数组下标5的位置
3. 第三名在原始数组下标3的位置
4. 第四名在原始数组下标1的位置
5. 第五名在原始数组下标4的位置
6. 第六名在原始数组下标0的位置

都知道第几名在原始数组的什么位置，接下来怎么做就不用说了，直接上代码
```python
def find_relative_ranks(nums):
    max = 0  # 获取分数的最大值
    for num in nums:
        if num > max:
            max = num
    nums_index = [-1] * (max + 1)  # 申请一个包含max+1个全是-1的数组
    for i in range(len(nums)):
        nums_index[nums[i]] = i  # 把该元素对应的下标处的值置为在原始数组中的索引下标
    rank = 1  # 排名
    while max >= 0:
        if nums_index[max] >= 0:
            if rank == 1:
                nums[nums_index[max]] = "Gold Medal"
            elif rank == 2:
                nums[nums_index[max]] = "Silver Medal"
            elif rank == 3:
                nums[nums_index[max]] = "Bronze Medal"
            else:
                nums[nums_index[max]] = f"{rank}"
            rank += 1
        max -= 1
    return nums
```
