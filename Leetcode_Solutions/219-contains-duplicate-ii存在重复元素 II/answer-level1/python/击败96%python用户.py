class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        hash={}
        list=[]
        for i in nums:
            if i in hash:
                hash[i]+=1
            else:
                hash[i]=1

        for i in hash:
            if hash[i]>=2:
                list.append(i)

        for i in list:
            for n in range(len(nums)):
                if nums[n]==i:
                    for m in range(1,k+1):
                        if n+m<=len(nums)-1 and nums[n+m]==i:
                            return True
        return False