class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        l_seq = len(seq)
        ans = [0]*l_seq
        for i in range(l_seq):
        #奇数位的“(”为0，偶数位为1
            if seq[i] == '(':
                if i % 2 == 0:
                    ans[i] = 0
                else:
                    ans[i] = 1
            else:
        #若“)”前为“(”则取值相同，若“)”前为“)”则取反
                if seq[i-1] == '(':
                    ans[i] = ans[i-1]
                else:
                    ans[i] = (ans[i-1]+1)&1
        return ans