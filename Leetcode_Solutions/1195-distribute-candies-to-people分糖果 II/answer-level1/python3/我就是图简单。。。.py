#好吧应该用官方题解中那个用数学推出来的关于最后一项的推导去做
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        #首先想到的是暴力模拟，但数值太大1千万。额，试试
        #额。。过了。。。好吧，打算用叠加那个算法去试试的。
        lt=[0 for i in range(num_people)]
        now_c=1
        while(candies!=0):
            for i in range(num_people):
                if(candies >= now_c):
                    candies-=now_c
                else:
                    now_c=candies
                    candies=0
                lt[i]+=now_c
                now_c+=1
        return lt