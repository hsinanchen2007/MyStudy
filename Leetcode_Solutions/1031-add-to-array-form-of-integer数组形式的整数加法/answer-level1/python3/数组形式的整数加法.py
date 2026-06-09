class Solution:
    def addToArrayForm(self, A, K):
        a = int(''.join(str(t) for t in A))
        sum = list(map(int,str(a + K)))
        print(sum)
if __name__ == '__main__':
    arr = [1, 2, 0, 0]
    k = 890
    s = Solution()
    s.addToArrayForm(arr, k)