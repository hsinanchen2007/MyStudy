class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        hash_set = [0]*len(nums)
        rep,los=0,0
        for i in nums:
            hash_set[i-1]+=1
        for i in range(len(hash_set)):
            if hash_set[i]==2:
                rep = i+1
            if hash_set[i]==0:
                los = i+1
        return [rep,los]