class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        vec = []
        left = 1
        right = 2
        while left < right:
            sum_ = (left + right) * (right - left + 1) / 2
            res = []
            if sum_ == target:
                
                i = left
                while i <= right:
                    res.append(i)
                    i+=1
                vec.append(res)
                left+=1
                right+=1
            elif sum_ < target:
                right+=1
            else:
                left+=1
        return vec