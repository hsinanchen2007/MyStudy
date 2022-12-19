class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        coloumList=list(zip(*matrix))
        List=[]
        for raw in matrix:
            index=raw.index(min(raw))
            if raw[index]==max(coloumList[index]):
                List.append(raw[index])
        return List

每行找最小，与每列最大比较