最直观的方法是不断地遍历数组，如果还有糖就一直分，直到没有糖为止

``` python

class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:

        res=[0]*num_people

        give=0

        while candies>0:
            res[give%num_people]+=min(give+1,candies)
            give+=1
            candies-=give

        return res


```




