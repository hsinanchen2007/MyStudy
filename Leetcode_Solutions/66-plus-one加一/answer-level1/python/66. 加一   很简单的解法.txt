class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s1 = ""
        l1 = []
        for i in range(len(digits)):
            s1=s1 + str(digits[i])
        s1 = int(s1)+1
        s1 = str(s1)

        for i in range(len(s1)):
            l1 = l1 + list(s1[i])
        return l1
        