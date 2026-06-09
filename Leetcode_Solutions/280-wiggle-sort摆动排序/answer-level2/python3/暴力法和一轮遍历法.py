暴力法：执行用时:136ms,在所有Python3提交中击败了55.88%的用户；内存消耗:14.8MB,在所有Python3提交中击败了100.00%的用户
先从小到大排序，再将第3个与第2个叫唤，第5个和第4个交换，……

    def wiggleSort(self, nums: List[int]) -> None:
        nums.sort()
        for i in range(1,len(nums),2):
            if i==len(nums)-1:
                break
            nums[i],nums[i+1]=nums[i+1],nums[i]
        return nums

一轮遍历法：执行用时:120ms,在所有Python3提交中击败了67.65%的用户；内存消耗:14.6MB,在所有Python3提交中击败了100.00%的用户

    def wiggleSort(self, nums: List[int]) -> None:
        for i in range(len(nums)-1):
            if (i+1)%2==1:
                if nums[i]<nums[i+1]:
                    pass
                else:
                    nums[i],nums[i+1]=nums[i+1],nums[i]
            else:
                if nums[i]>nums[i+1]:
                    pass
                else:
                    nums[i],nums[i+1]=nums[i+1],nums[i]
        return nums
            