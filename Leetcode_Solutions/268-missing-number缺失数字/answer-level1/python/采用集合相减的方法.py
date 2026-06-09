   
集合对内存消耗比较大就是，速度还是可以的


     nums_set = set(nums)
    
    real_set = set(range(0,len(nums)+1))
    
    diff_set = real_set - nums_set
    
    return list(diff_set)[0]