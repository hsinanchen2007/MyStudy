思路: 用的python解法，非常容易理解，首先依次取出三个数(任意三个数都得取到)，为了保证0 <= i < j < k < n,用了三个循环，第一个循环只需要取到n-2个，后面依次类推，最后循环写完直接判断计数即可，是不是特别好理解呢?

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        nums = 0
        for i in range(len(rating)-2):
            for j in range(i,len(rating)-1):
                for k in range(j,len(rating)):
                    if rating[i] < rating[j] < rating[k] or rating[i] > rating[j] > rating[k]:
                        nums += 1
        return nums
