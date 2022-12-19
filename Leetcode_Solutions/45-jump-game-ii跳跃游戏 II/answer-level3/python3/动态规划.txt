`class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        if size <= 1:
            return 0
        df = [0] * size
        df[0] = nums[0]
        for i in range(1,size):

            if df[i-1] >= i :
                df[i] = max(df[i-1],nums[i] + i)
        
        #print(df)
        k = 1
        a = df[0]
        while True:
            if a < size - 1:
                a = df[a]
                k += 1
            else:
                return k`

先动态路由一遍，然后便利一遍DF，大于列表长度即可