class Solution:
    def findLucky(self, arr: List[int]) -> int:
        dictres={}
        for i in arr:
            if i not in dictres.keys():
                dictres[i]=1
            else:
                dictres[i]+=1
        min_luck=-1
        for i in dictres.keys():
            if dictres[i]==i:
                if i>min_luck:
                    min_luck=i
        return min_luck
