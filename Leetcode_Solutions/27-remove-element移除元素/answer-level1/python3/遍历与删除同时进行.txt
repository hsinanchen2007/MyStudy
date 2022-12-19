def removeElement(nums,val):
    i=0
    while i<len(nums):
        if nums[i]==val:
            nums.remove(nums[i])
        else:
            i+=1
    return len(nums)

print(removeElement([1,2,2,3],2))