class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        n = int(((1+8*candies)**0.5-1)/2)
        last = candies-n*(n+1)//2
        res = [0]*num_people
        loops = n//num_people
        temp = 0
        for i in range(num_people):
            if i+1+loops*num_people<=n:
                res[i] = (loops+1)*(i+1)+(loops+1)*loops*num_people//2
            else:
                if temp == 0:
                    res[i] = loops * (i + 1) + loops * (loops - 1) * num_people // 2 + last
                    temp = 1
                else:
                    res[i] = loops * (i + 1) + loops * (loops - 1) * num_people // 2

        return res