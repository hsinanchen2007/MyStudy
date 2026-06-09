
```
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        n = len(nums)
        self.max_len = 0
        _index_set = set()  

        def helper(i, level, _index_set):  # i为下标，level为递归层次，_index_set记录已访问的小标
            if i in _index_set:
                return
            _index_set.add(i)
            self.max_len = max(self.max_len, level + 1)
            helper(nums[i], level + 1, _index_set)
        for i in range(n):
            helper(i, 0, _index_set)
        return self.max_len
```
