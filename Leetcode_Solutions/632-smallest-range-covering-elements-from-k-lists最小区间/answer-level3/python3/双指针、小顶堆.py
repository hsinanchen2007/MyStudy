```python
from typing import List
import heapq

class Solution:
    # 超时
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        maxmins = [(nums[i][0], nums[i][-1]) for i in range(len(nums))]
        max_ = max(maxmins, key=lambda x: x[1])[-1]
        left = min(maxmins, key=lambda x: x[0])[0]
        right = max(maxmins, key=lambda x: x[0])[0]
        res = [left, right]
        cnts = []
        for i in range(len(nums)):
            j = 0
            while j < len(nums) and nums[i][j] <= right:
                j += 1
            cnts.append([0, j - 1])
        while left <= right <= max_:
            while not all(map(lambda x: x[-1] - x[0] >= 0, cnts)) and right <= max_:
                right += 1
                for i in range(len(cnts)):
                    low, high = cnts[i]
                    while high < len(nums[i]) and nums[i][high] <= right:
                        high += 1
                    cnts[i][-1] = high - 1
            if (right - left < res[-1] - res[0] or (right - left == res[-1] - res[0] and left < res[0])):
                res[0], res[-1] = left, right
            left += 1
            for i in range(len(cnts)):
                low, high = cnts[i]
                while low <= high and nums[i][low] < left:
                    low += 1
                cnts[i][0] = low
        return res

    # 超时
    def smallestRange1(self, nums: List[List[int]]) -> List[int]:
        right = max_ = -float('inf')
        left = float('inf')
        for i in range(len(nums)):
            max_ = max(max_, nums[i][-1])
            left = min(left, nums[i][0])
            right = max(right, nums[i][0])
        res = [left, right]
        cnts = []
        for i in range(len(nums)):
            j = 0
            while j < len(nums[i]) and nums[i][j] <= right:
                j += 1
            cnts.append([0, j - 1])
        count = len(nums)
        while left <= right <= max_:
            while count < len(nums) and right <= max_:
                right += 1
                for i in range(len(cnts)):
                    low, high = cnts[i]
                    tmp = True if high < low else False
                    while high < len(nums[i]) and nums[i][high] <= right:
                        high += 1
                    if high - low >= 1 and tmp: count += 1
                    cnts[i][-1] = high - 1
            if (right - left < res[-1] - res[0] or (right - left == res[-1] - res[0] and left < res[0])):
                res[0], res[-1] = left, right
            left += 1
            for i in range(len(cnts)):
                low, high = cnts[i]
                while low <= high and nums[i][low] < left:
                    low += 1
                if high - low < 0: count -= 1
                cnts[i][0] = low
        return res

    def smallestRange2(self, nums: List[List[int]]) -> List[int]:
        new_nums = [(n, i) for i, num in enumerate(nums) for n in num]
        new_nums.sort(key=lambda x: x[0])
        left = right = 0
        # 每个列表有多少个元素在窗口内
        count = [0] * len(nums)
        cnt = 0
        res = [new_nums[0][0], new_nums[-1][0]]
        while right < len(new_nums):
            tmp = False
            # 判断扩展之前是否满足，之前若满足那么则没有多包括进一个列表的元素
            if count[new_nums[right][-1]] < 1: tmp = True
            count[new_nums[right][-1]] += 1
            if tmp and count[new_nums[right][-1]] >= 1: cnt += 1
            # 若每个列表都至少有一个元素在窗口内，则试着移动左指针缩小区间
            while cnt >= len(nums):
                if (new_nums[right][0] - new_nums[left][0] < res[-1] - res[0] or
                        new_nums[right][0] - new_nums[left][0] == res[-1] - res[0] and new_nums[left][0] < res[0]):
                    res[0], res[-1] = new_nums[left][0], new_nums[right][0]
                count[new_nums[left][-1]] -= 1
                if count[new_nums[left][-1]] == 0: cnt -= 1
                left += 1
            right += 1
        return res

    def smallestRange3(self, nums: List[List[int]]) -> List[int]:
        heap, cur_max = [], -float('inf')
        # 首先将每个列表的第一个元素加入到小顶堆中满足题目要求，同时更新当前最大值
        for i in range(len(nums)):
            heapq.heappush(heap, (nums[i][0], i))
            cur_max = max(cur_max, nums[i][0])
        cur_min, cur_idx = heapq.heappop(heap)
        res = [cur_min, cur_max]
        # 记录每个列表当前移动到第几个元素了
        cur_idxs = [1] * len(nums)
        # 如果当前弹出的元素所在列表没有后一个元素了，那么后面无法再满足题目要求，退出循环
        while cur_idxs[cur_idx] < len(nums[cur_idx]):
            tmp = nums[cur_idx][cur_idxs[cur_idx]]
            cur_max = max(tmp, cur_max)
            # 弹出第几个列表的元素就相应地加入第几个列表的元素，保持满足题目要求
            heapq.heappush(heap, (tmp, cur_idx))
            cur_idxs[cur_idx] += 1
            cur_min, cur_idx = heapq.heappop(heap)
            if (cur_max - cur_min < res[-1] - res[0] or
                    cur_max - cur_min < res[-1] - res[0] and cur_min < res[0]):
                res[0], res[-1] = cur_min, cur_max
        return res
```