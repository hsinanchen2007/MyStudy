### 解题思路
如果糖够，那么每次全给糖的数量应该是1+.....+n
n+1 + ....... + 2n
.......
如果第k次给的话，应该是首项为(k-1)n + 1，尾项为kn的等差数列
求和为 $((n*(k-1) + 1) + n*k) * n /2$
那么第m个小朋友获得的糖数位
m +    n+ m +    2n + m    +... +    (k-1)n + m 
就是km + (0 + (k-1)n)*n/2
或者说km + (n + (k-1)n)*(k-1)/2
先遍历一下看能完全分糖几次，把这些都算出来
然后建立循环填充糖数，还有剩余糖果时就是前面算出来的分糖果+新分的，没有就直接是之前分的糖果
### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int):
        #在第k次给糖，如果能全部分给每个小朋友的话，需要((n*(k-1) + 1) + n*k) * n /2 颗糖果,
        #第m个小朋友获得的糖果是k*m+ (0 + (k*n))*n/2 颗糖
        k = 1
        while candies > self.needCandy(k,num_people):
            candies -= self.needCandy(k,num_people)
            k += 1
        k = k - 1
        res = []
        for i in range(num_people):
            if candies >= (i+1) + k * num_people:
                res.append(int((i+1) + k * num_people + k*(i+1) + k* num_people * (k-1) /2))
                candies -= (i+1) + k * num_people
            elif not candies == 0:
                res.append(int( k*(i+1) + k* num_people * (k-1) /2 + candies))
                candies = 0
            elif candies == 0:
                res.append(int( k*(i+1) + k* num_people * (k-1) /2))
        return res

    def needCandy(self,k,n):
        if (k>0):
            return ((n*(k-1) + 1) + n*k) * n /2 
        else:
            return 0
```