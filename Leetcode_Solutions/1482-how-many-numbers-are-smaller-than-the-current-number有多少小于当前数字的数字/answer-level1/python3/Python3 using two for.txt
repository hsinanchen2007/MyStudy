### 解题思路
We need two for to test it

### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        #formation counters
        counters=[]
        for num in nums:
            #formation counter
            counter=0
            #Compare it with other nums
            #Creat othernums
            othernums=[]
            for x in nums: 
                if x!=num:
                    othernums.append(x)
            #start to compare
            for x in othernums:
                if num>x:
                    counter+=1
            counters.append(counter)
        return counters
```