class Solution(object):
    def __init__(self):
        "When flag=1 plus idx by 1; otherwise, minus idx by 1"
        self.flag = 1
        self.idx = 0

    def get_idx(self, maxv):
        if self.flag == 1 and self.idx < maxv:
            self.idx += 1
            if self.idx == maxv: self.flag = 0
        else:
            self.idx -= 1
            if self.idx == 1: self.flag = 1

    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        D={}
        for i in range(1,numRows+1):
            D[i] = []

        for j in s:
            self.get_idx(numRows)
            D[self.idx].append(j)

        res=""
        for k in D:
            res=res + "".join(D[k])
        return res

if __name__ == '__main__':
    A = Solution()
    A.convert('PAYPALISHIRING', 4)