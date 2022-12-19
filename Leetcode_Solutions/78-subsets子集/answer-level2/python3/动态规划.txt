构建一个数组dp[]
dp[0]就是指针第0个数的子集，显然就是它本身list[0]
dp[i]就是dp[i-1]内所有的子集+（dp[i-1]内每个子集都append（list[i]））+[list[i]]

最后返回dp[len(list)-1]
def subsets( nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    dp =[[] for i in range(len(nums))]
    dp[0].append([nums[0]])

    for j in range(1,len(nums)):

        for l in dp[j-1]:
            dp[j].append(l)#加入前一项的所有子集
            l_copy = list(l)
            l_copy.append(nums[j])
            dp[j].append(l_copy)#加入前一项每个子集都加上当前数的集合

        dp[j].append([nums[j]])#单独加入当前数
    dp[len(nums) - 1].append([])#加入空数列
    return dp[len(nums)-1]