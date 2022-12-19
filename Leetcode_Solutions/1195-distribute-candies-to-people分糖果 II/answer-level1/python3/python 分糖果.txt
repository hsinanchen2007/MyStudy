### 解题思路
依次遍历list。进行分放，依次加一，到头重新再开始即可

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        result=[0]*num_people
        one=1
        i=0
        while i < num_people:
            if candies >= one:
                result[i]+=one
                candies=candies-one
                one=one+1
            elif candies < one:
                result[i]+=candies
                break
            if i==num_people-1:
                i=0
            else:
                i=i+1
        return result


            
```