### 解题思路
这个问题比较简单，用暴露解法就好。
分配的糖果数量，每分配一次，加1，当糖果少于当前应分配数量时，将剩余糖果给当前小朋友，退出循环即可

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        people_list=[0]*num_people
        i=0
        while candies>0:
            for p in range(len(people_list)):
                i+=1
                if candies<=0:
                    break
                elif candies<i:
                    people_list[p]+=candies
                    candies-=i
                elif candies>=i:
                    people_list[p]+=i
                    candies-=i

        return people_list
```