```python
def checkPossibility(nums):
    i = 0
    j = len(nums) - 1
    while i < j and nums[i] <= nums[i + 1]:
        i += 1
    while i < j and nums[j] >= nums[j - 1]:
        j -= 1
    if i == len(nums) - 1:
        return True
    if i == j - 1:
        if (i - 1 >= 0 and nums[i - 1] < nums[j]) or (j + 1 < len(nums) and nums[i] < nums[j + 1]):
            return True
        elif i == 0 or j == len(nums) - 1:
            return True
        else:
            return False
    else:
        return False