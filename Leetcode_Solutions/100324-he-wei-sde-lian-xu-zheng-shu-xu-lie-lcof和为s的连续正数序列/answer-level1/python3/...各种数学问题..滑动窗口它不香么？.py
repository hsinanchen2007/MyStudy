



class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        
        left, right = 1, 1
        windows = []
        res = []
        while right < target:
            
            if sum(windows) == target:
                res.append(windows.copy())
                left += 1
                windows.pop(0)
            elif  sum(windows) > target:
                windows.pop(0)
                left += 1
            else:
                windows.append(right)
                right += 1
        
        return res