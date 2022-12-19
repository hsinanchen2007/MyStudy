- 参考 https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/zhi-chu-xian-yi-ci-de-shu-xi-lie-wei-yun-suan-by-a/

 ```

class Solution:
    # leetcode 260 面试题 56
    # https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/zhi-chu-xian-yi-ci-de-shu-xi-lie-wei-yun-suan-by-a/
    # 题目大意是除了两个数字出现一次，其他都出现了两次，让我们找到这个两个数。
    # [1,2,2,5] 返回 [1,5]
    def singleNumbers(self, nums):
        #灵活运用异或运算
        ret=a=b=0
        for num in nums:
            ret = ret^num
        
        h = 1 #h是为了找到两个数字第一个不同的位置 一个是0 一个是 1
        while ret & h ==0:
            h <<= 1

        for num in nums:
            if num &h == 0:
                
                a ^= num
            else:
                b^= num
                print(num,h)
        return [a,b]
    

    #LeetCode 137
    # 只有一个数出现了一次，其他都出现了三次
    # [1,2,2,2,3,3,3] 返回1 
    # 按bit操作，除去那个数，其余数在任意bit位上 1 的个数应该被三整除
    def threeOne(self,arr):
        res = 0
        for i in range(32):
            cnt = 0 #计数 1 出现的次数
            bit = 1 << i
            for num in arr:
                if num & bit != 0: #!=0 he == 1 大大不同啊
                    cnt += 1
            if cnt %2 !=0:
                # print(bit)
                res |= bit
            # bit <<= 1
        return res

    # 出现三次的数 出现一次的数 找出 出现一次的 
    # https://leetcode-cn.com/problems/single-number-ii/solution/zi-dong-ji-wei-yun-suan-zui-xiang-xi-de-tui-dao-gu/
    def singleNumber(self, nums) -> int:
        seen_once = seen_twice = 0
        
        for num in nums:
            # first appearance: 
            # add num to seen_once 
            # don't add to seen_twice because of presence in seen_once
            
            # second appearance: 
            # remove num from seen_once 
            # add num to seen_twice
            
            # third appearance: 
            # don't add to seen_once because of presence in seen_twice
            # remove num from seen_twice
            seen_once = ~seen_twice & (seen_once ^ num)
            seen_twice = ~seen_once & (seen_twice ^ num)

        return seen_once


# 面试题 17.19. 消失的两个数字
# 给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？
# 以任意顺序返回这两个数字均可。
# https://leetcode-cn.com/problems/missing-two-lcci/solution/
# 输入: [1]
# 输出: [2,3]

# 输入: [2,3]
# 输出: [1,4]
class Solution:
    def missingTwo(self, nums):
        N = len(nums)+2
        ret = 0
        a=0
        b=0
        for i in range(1,N+1):
            ret ^= i
        
        for num in nums:
            ret ^= num
        
        h = 1
        while ret & h ==0:
            h <<= 1

        #没有重复的部分 都是出现了一次
        for num in nums:
            if num & h ==0:
                a ^= num
            else:
                b ^= num

        for num in range(1,N+1):
            if num & h == 0:
                a ^= num
            else:
                b ^= num
        return [a,b]                     
# print(Solution().missingTwo([2]))

# https://leetcode-cn.com/problems/set-mismatch/solution/cuo-wu-de-ji-he-by-leetcode/
# LeetCode 645. 错误的集合
# 集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
# 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
# 输入: nums = [1,2,2,4]
# 输出: [2,3]
class Solution:
    def findErrorNums(self, nums):
        def missingTwo(arr):
            ret = 0
            for num in arr:
                ret ^= num
            
            h = 1
            while h&ret==0:
                h <<= 1

            a=b=0
            for num in arr:
                if num&h==0:
                    a^=num
                else:
                    b ^= num
            return [a,b]
        
        arr = [i for i in range(1,len(nums)+1)] + nums
        a,b = missingTwo(arr)
        for num in nums:
            if num == a:
                return [a,b]
        return [b,a]

print(Solution().findErrorNums([1,3,3,4]))
```
