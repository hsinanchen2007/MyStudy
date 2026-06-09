`class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        
        a = []
        result = [0]*len(S)
        for j in range(len(S)):
            if C == S[j]:
                a.append(j)

        for i in range(len(a)):
            if i == 0:
                result[:a[i]] = range(a[i],0,-1)
            else:
                    c = []
                    d = []
                    m = range(1, (a[i]-a[i-1]) // 2 + 1)
                    if a[i] - a[i-1] > 2:
                        if (a[i] - a[i-1])%2 != 0:
                            n = range((a[i]-a[i-1]) // 2, 0, -1)
                        else:
                            n = range(((a[i] - a[i - 1]) // 2)-1, 0, -1)
                        d[:] = n

                    c[:] = m
                    result[a[i-1]+1:(len(range(1,a[i]-a[i-1])))] = c + d

        result[a[len(a)-1]+1:] = range(1,len(S)-a[len(a)-1])

                    
        return result`