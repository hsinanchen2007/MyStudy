class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        list = sorted(intervals, key = lambda x:x[0])
        for i, l in enumerate(list):
            if i < len(list)-1:
                while list[i][1] >= list[i+1][0]:
                    list[i] = [list[i][0],max(list[i+1][1],list[i][1])]
                    del list[i+1]
                    if i >= len(list) - 1:
                        break
        return list