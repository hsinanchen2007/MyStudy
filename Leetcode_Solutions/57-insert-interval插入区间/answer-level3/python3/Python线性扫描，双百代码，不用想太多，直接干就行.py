class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ret = []
        flag = False
        isAdd = False
        for l, r in intervals:
            if r < newInterval[0] or l > newInterval[1]:
                if flag:
                    ret.append(newInterval)
                    flag = False
                    isAdd = True
                if l > newInterval[1] and not isAdd:
                    ret.append(newInterval)
                    isAdd = True
                ret.append([l,r])
            else:
                flag = True
                newInterval = [min(newInterval[0], l), max(newInterval[1], r)]
        if not isAdd:
            ret.append(newInterval)
        return ret