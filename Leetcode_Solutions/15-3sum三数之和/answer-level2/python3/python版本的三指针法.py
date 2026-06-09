参考四数之和的某位大神的题解，也可适用于三数之和等于target(任意值)

- 定义三个指针，分别为i,j,k.
- 初始情况下，i指向nums[0],k指向nums[k],及i，k分别为首尾指针。j指针位于i，k之间
- 针对i每次移动，计算该i对应的最大和最小三数之和，进行筛选，提高效率。
- 在移动三个指针过程中，判断是否有重复。
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        #边界条件，nums为空，或元素不足三个，返回None
        if not nums or length < 3:
            return None
        #先对数组排序
        nums.sort()
        result = []
        #构造三个指针，i，j，k,其中i<j<k，k指向末尾
        for i in range(length - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
           #当前最小三数和大于0，后面更大的就不用考虑了
            min1 = nums[i] + nums[i + 1] + nums[i + 2]
            if min1 > 0:
                break
            #当前最大三数和小于0，说明后面更小的和也没戏，忽略这个num[i],选择i+1
            max1 = nums[i] + nums[length - 1] + nums[length - 2]
            if max1 < 0:
                continue

            j = i + 1
            k = length - 1
            while j < k:
                curr = nums[i] + nums[j] + nums[k]
                if curr == 0:
                    result.append([nums[i], nums[j], nums[k]])
                    #j指针右移
                    j += 1
                    #避免重复
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    #k指针左移
                    k -= 1
                    #避免重复
                    while j < k and i < k and nums[k] == nums[k + 1]:
                        k -= 1
                #k指针左移，因为三数和偏大，需向左压缩      
                elif curr > 0:
                    k -= 1
                #j指针右移，因为三数和偏小，需向右压缩 
                elif curr < 0:
                    j += 1
        return result
