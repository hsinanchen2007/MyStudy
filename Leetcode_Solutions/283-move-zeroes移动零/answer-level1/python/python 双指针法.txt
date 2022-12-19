m = len(nums)
    index =0
    step = 0

    while step<m:
        if nums[step]!=0:
            nums[index]=nums[step]
            index +=1
        step+=1
    for  i in range(index,m):
        nums[i]=0