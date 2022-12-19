```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        n1 = 0
        aa = []
        list1 = list(range(1,n+1))
        result = []
        for ok in range(1,n-k+2):
            result.append([ok])
        for	i in range(k-1):
            n1 = len(result)
            for j in range(n1):
                n2 = len(result[j])
                if k > n2+1:
                    aaa = -(k-n2-1)
                else:
                    aaa = len(list1)+1
                for kk in list1[result[j][-1]:aaa]:
                    aa = result[j][:]
                    aa.append(kk)
                    result.append(aa)
            for l in range(n1):
                result.pop(0)
        return(result)	

```
