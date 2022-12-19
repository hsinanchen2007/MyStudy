class Solution:
    def balancedStringSplit(self, s: str) -> int:
        sum = 0
        dict1 = {'L':0,'R':0}
        for i in s:
            dict1[i] += 1
            if dict1['L'] == dict1['R']:
                sum += 1
        return sum



