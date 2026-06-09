### 解题思路
1.暴力破解，直接利用对num_people求余来循环给小朋友发糖果
2.由于每次一个循环，发给小朋友的糖果数是一个等差数列，首项就是第一轮循环发的糖果总数，公差就是num_people的平方。找到那一次循环后，下一次循环可以把糖发完，在最后一次循环进行暴力法发糖果

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        #暴力破解
        # ans = [0]*num_people#糖果序列
        # i = 0
        # while(candies):
        #     ans[i%num_people] += min(i+1, candies)
        #     candies-=min(i+1, candies)
        #     i+=1
        # return ans
        
        #公式法
        a1 = int(num_people*(num_people+1)//2) #首项
        if(candies<a1):
            ans = [0]*num_people#糖果序列
            self.computer(candies, num_people, 0, ans)
        else:
            d = num_people*num_people #公比
            n = 1
            for i in range(int(candies//a1)):
                S = int(n*a1+(n*(n-1)*d)//2)#等比公式求和
                Sn = int((n+1)*a1+(n*(n+1)*d)//2)
                if(S<=candies and candies<=Sn):
                    candies -=S
                    break
                else:
                    n+=1
            ans = [int(n*i+(n*(n-1)*num_people)//2) for i in range(1,num_people+1)]
            if(candies):
                self.computer(candies, num_people, num_people*n, ans)
        return ans
    def computer(self, candies, num_people, x, ans):
        while(candies):
                ans[x%num_people] += min(x+1, candies)
                candies-=min(x+1, candies)
                x+=1
        
```