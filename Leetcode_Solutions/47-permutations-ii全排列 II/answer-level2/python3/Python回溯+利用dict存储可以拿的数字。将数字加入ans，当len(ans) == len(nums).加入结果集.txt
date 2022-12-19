"""
class Solution:
    def permuteUnique(self, nums):
        nums.sort()
        res = []
        ans = []
        size = len(nums)
        begin = 0
        dic = {}
        # 用字典记录可以拿的数
        for key in nums:
            if dic.__contains__(key):
                dic[key] += 1
            else:
                dic[key] = 1

        def allSort(dic,ans,res):
            if len(ans) == size:
                res.append(ans[:])
                return
            for key,value in dic.items():
                if value == 0:
                    continue
                ans.append(key)
                value = value - 1
                dic[key] = value
                allSort(dic,ans,res)
                ans.pop()
                value += 1
                dic[key] = value

        allSort(dic,ans,res)
        return res


if __name__ == '__main__':
    nums = [1,1,2]
    solution = Solution()
    result = solution.permuteUnique(nums)
    print(result)

"""