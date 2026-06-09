class Solution:
    def compressString(self, S: str) -> str:
        if len(S) == 0:
            return ''
        if len(S) == 1:
            return S
        res =''
        cnt = 1
        for i in range(1,len(S)):
            if S[i] == S[i-1]:
                cnt += 1
                if i == len(S) - 1:
                    res += S[i-1] + str(cnt)
            else:
                res += S[i-1] + str(cnt)
                cnt = 1
                if i == len(S) - 1:
                    res += S[i] + str(cnt)

        return res if len(res) < len(S) else S