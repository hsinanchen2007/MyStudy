class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        numbers.append(numbers[1])
        numbers.append(numbers[0])
        return numbers[2:]