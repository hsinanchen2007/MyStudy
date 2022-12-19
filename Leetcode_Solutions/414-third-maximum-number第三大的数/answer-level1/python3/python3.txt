```
	nums = list(set(nums))
	fir_max = float("-inf")
	sec_max = float("-inf")
	third_max = float("-inf")

	for i in range(len(nums)):
		if nums[i] > fir_max:
			fir_max, sec_max, third_max = nums[i], fir_max, sec_max
		elif nums[i] > sec_max:
			sec_max, third_max = nums[i], sec_max
		elif nums[i] > third_max:
			third_max = nums[i]
	return fir_max if third_max == float("-inf") else third_max
```
