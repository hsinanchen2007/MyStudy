target=sum(nums)
if target%2!=0:
    return False 

target=target//2
res=[False if nums[0]!=val else True for val in range(target+1)]
for i in range(1,len(nums)):
    for j in range(target,-1,-1):
        if j>=nums[i]:
            res[j]=res[j] or res[j-nums[i]]
return res[-1]