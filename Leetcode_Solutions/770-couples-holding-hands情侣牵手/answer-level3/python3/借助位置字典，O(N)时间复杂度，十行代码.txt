class Solution:
    def minSwapsCouples(self, row: List[int]) -> int: 
        change = 0
        index = {row[i]:i for i in range(len(row))}
        for i in range(int(len(row)/2)):
            couple_0,neighbor = row[2*i],row[2*i+1]
            couple_1 = couple_0+1 if couple_0 % 2 == 0 else couple_0-1
            if not (abs(couple_0-neighbor)==1 and max(couple_0,neighbor)%2 == 1):
                index[neighbor],index[couple_1] = index[couple_1],2*i+1
                row[index[neighbor]],row[index[couple_1]] = neighbor,couple_1
                change += 1 
        return change