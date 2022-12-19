```
class Solution:
    def pourWater(self, heights: List[int], V: int, K: int) -> List[int]:

        for _ in range(V):
            min_height=heights[K]
            min_index=K
            for i in range(K-1,-1,-1):
                if heights[i]<min_height:
                    min_height=heights[i]
                    min_index=i
                if heights[i]>min_height:
                    break
            if min_index==K:
                for i in range(K+1,len(heights)):
                    if heights[i]<min_height:
                        min_height=heights[i]
                        min_index=i
                    if heights[i]>min_height:
                        break
            heights[min_index]+=1
        return heights
```
