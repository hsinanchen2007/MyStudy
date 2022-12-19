解题思路：类型转换

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = [str(i) for i in digits]
        x = ''.join(n)
        v = int(x) + 1
        return([int(i) for i in str(v)])