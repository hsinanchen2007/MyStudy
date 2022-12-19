class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        dict1 = {}
        for i,num in enumerate(B):
            dict1[num] = i
        return [dict1[x] for x in A]