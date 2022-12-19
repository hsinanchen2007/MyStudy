### 解题思路
此处撰写解题思路
使用l双层循环，外层循环控制糖块的个数，内层循环是为每个人分配的糖果
### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        people = []
        for i in range(num_people):
            people.append(0)
        num = 1
        sumc=0
        while(candies-sumc>0):
            for i in range(num_people):
                if(candies-sumc-num>=0):
                    people[i] = num+people[i]
                    sumc = sumc+num
                    num=num+1
                else:
                    people[i] = candies - sumc +people[i]
                    sumc = candies
            i = 0
        return people

```