Python collection减一下

class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        stats_B = [collections.Counter(x) for x in B]
        b = stats_B[0]
        for x in stats_B:
            b |= x
        res = []
        for i in range(len(A)):
            sta = collections.Counter(A[i])
            if not b-sta:
                res.append(A[i])
            #print(A[i]," ",b-sta)
        return res
