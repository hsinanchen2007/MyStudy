```

        """
        Do not return anything, modify nums in-place instead.
        """
        flag_0 = []
        for i in range(len(nums)):
            if nums[i] == 0:
                flag_0.append(i)

        for i in range(len(flag_0)):
            nums.pop(flag_0[i]-i)
            nums.append(0)
        

```
