class Solution:
    def numTeams(self, rating):
        if len(rating) < 3:
            return 0
        count = 0
        length = len(rating)
        for i in range(length):
            for j in range(i + 1, length):
                for k in range(j + 1, length):
                    if rating[i] < rating[j] and rating[j] < rating[k]:
                        count += 1
                    elif rating[i] > rating[j] and rating[j] > rating[k]:
                        count += 1
        return count


时间复杂度：三个for循环 O(n^3)
空间复杂度：只有两个变量，属于常数级别O(1)