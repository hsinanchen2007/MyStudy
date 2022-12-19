思路：实现加法的过程

用递归的方法解决：

class Solution:

    def plusOne(self, digits: List[int]) -> List[int]:

        return self.addOne(digits,len(digits)-1)

    def addOne(self,digits,index):
        if index == -1:
            digits.insert(0,1)
            return digits
        digits[index] = digits[index] + 1
        if digits[index] == 10:
            digits[index] = 0
            return self.addOne(digits, index - 1)
        return digits
