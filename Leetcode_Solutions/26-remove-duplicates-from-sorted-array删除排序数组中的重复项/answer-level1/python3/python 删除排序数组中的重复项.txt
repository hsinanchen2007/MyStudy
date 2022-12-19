def removeDuplicates(nums):
    for i in range(len(nums))[::-1]:#反转列表，从后向前进行对比。进程为1个数
        #由于是从后向前进行对比，所以不会有跳跃而漏掉数字
        if i-1 != -1 and nums[i-1] == nums[i]:#前一个条件为判断是为标签界定边界的。
                del nums[i] 
    return print(nums)

看了下30ms就计算完成了。