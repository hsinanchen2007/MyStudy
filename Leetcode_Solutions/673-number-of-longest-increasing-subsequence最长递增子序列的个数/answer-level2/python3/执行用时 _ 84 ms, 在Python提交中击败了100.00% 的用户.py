思想基本和求最长递增子序列的长度 类似。不同之处在于要记录每个位置 i 放数字num时的递增序列个数 dic[i][num]。
当数字 newnum 放在 i+1 位置时，dic[i+1][newnum] 的值为 dic[i] 中 小于newnum 的num 的序列个数之和。
```python
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        l = len(nums)
        dq = list()
        totals = list()
        for num in nums:
            index = len(dq)-1
            if not dq or num >dq[-1]:
                dq.append(num)
                totals.append(collections.defaultdict(int))
            else:
                while index >= 0 and dq[index]>= num:
                    index -= 1
                dq[index+1] = num
            if not index+1:
                totals[index+1][num] +=1
            else:
                totals[index+1][num] += sum([val for key,val in totals[index].items() if key <num ])
        return sum(totals[-1].values())