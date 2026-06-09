class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        k = -1
        while True:
            digits[k] = (digits[k] + 1) % 10
            if digits[k] == 0 and k > -len(digits):
                k -= 1
            elif digits[k] == 0 and k == -len(digits):
                return [1] + digits
            else:
                return digits
![image.png](https://pic.leetcode-cn.com/7858e4a492140b8f5f5f4aed7c8d906bb2efbcc26ec6b0dba8301c32260d4a88-image.png)
