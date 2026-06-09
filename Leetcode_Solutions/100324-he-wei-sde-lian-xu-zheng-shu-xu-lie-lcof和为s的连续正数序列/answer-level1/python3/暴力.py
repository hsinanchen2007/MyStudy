class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        mid = target // 2 + 1
        result = []
        for index in range(1, mid):
            temp_index = index
            _sum = index
            while _sum < target:
                _sum += temp_index + 1
                temp_index += 1
                if _sum == target:
                    result.append([i for i in range(index, temp_index+1)])
                    break
        return result