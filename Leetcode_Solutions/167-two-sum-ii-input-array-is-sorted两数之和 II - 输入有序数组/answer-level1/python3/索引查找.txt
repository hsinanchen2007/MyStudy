class Solution(object):
    def twoSum(self, numbers, target):
        for i in range(len(numbers)):
            current=target-numbers[i]
            if current in numbers[i+1:]:
                return [i+1,(numbers[i+1:].index(current))+i+2]