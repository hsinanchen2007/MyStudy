```
def optimize(nums):
    if len(nums) == 0 or nums == None:
        return []
    else:
        nums.sort()  # 排序，升序，时间复杂度O(NlogN)
        opt = [1] * len(nums)  # 用于计数，记录子集中最大值为nums[i]时所含元素个数，空间复杂度O(n)
        pre = [-1] * len(nums)  # pre[i]为子集中最大值为nums[i]时的前驱元素的下标，空间复杂度O(n)
        max_id = 0  # 用于标记目标子集的最大元素的下标，空间复杂度O(1)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and opt[j] + 1 > opt[i]:
                    opt[i] = opt[j] + 1
                    pre[i] = j
            if opt[i] > opt[max_id]:
                max_id = i
        # 循环遍历得到最后的目标子集，时间复杂度为O(n)，空间复杂度为O(n)
        result = []
        while max_id != -1:
            result.append(nums[max_id])
            max_id = pre[max_id]
        # res = list(reversed(result))
        return result # 从大到小显示
```
