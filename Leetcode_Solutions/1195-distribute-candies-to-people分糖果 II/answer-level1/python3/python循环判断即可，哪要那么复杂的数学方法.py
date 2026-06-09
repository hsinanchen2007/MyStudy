```
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res=[0]*num_people
        i,k=0,1                 #i表示当前小盆友序号（循环加一），k表示理应分k颗糖（每次加一）
        while candies:
            if k>candies:       #剩余糖果数<理应分配的个数，分完就跳出循环
                res[i]+=candies
                break
    
            res[i] += k         #给序号i的小盆友分k颗糖果
            candies-=k          #总糖果数目少了k

            k+=1
            i=(i+1)%num_people

        return res

```
