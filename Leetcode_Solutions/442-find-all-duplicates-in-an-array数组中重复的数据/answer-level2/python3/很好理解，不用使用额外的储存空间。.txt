执行用时:544ms,在所有Python3提交中击败了27.14%的用户
内存消耗:21.6MB,在所有Python3提交中击败了5.08%的用户

    def findDuplicates(self, nums: List[int]) -> List[int]:
        res=[]
        for i in nums:
            if nums[abs(i)-1]>0:
                nums[abs(i)-1]*=-1
            else:
                res.append(abs(i))
        return res