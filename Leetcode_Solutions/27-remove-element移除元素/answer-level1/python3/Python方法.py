这是python的方法，但是这好像对理解算法没太大帮助
```
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        times=nums.count(val)
        for i in range(times):
            nums.remove(val)
        return len(nums)
```

        

