class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if len(digits) == 1:
            if digits[0] == 9:
                return [1,0]
            else:
                return [digits[0]+1]
        else:
            if digits[-1] == 9:
                return self.plusOne(digits[:-1]) + [0]
            else:
                return digits[:-1]+[digits[-1]+1]