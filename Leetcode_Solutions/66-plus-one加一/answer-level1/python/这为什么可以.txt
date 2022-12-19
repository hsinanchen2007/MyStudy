    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
 
        for i,num in enumerate(digits):
            digits[i] = str(num)
        nums = eval("".join(digits))+1

        return str(nums)  