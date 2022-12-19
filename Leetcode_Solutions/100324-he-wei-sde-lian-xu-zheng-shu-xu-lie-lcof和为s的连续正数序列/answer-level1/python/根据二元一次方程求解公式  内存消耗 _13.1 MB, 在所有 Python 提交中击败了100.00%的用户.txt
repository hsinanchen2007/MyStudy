### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findContinuousSequence(self,target):
        res=[]

        for i in range(int(target/2)+1,1,-1):
            try:
                a=(1+math.sqrt(1+4*(i**2+i-2*target)))/2
                
            except Exception:
                break

            if a==int(a):
                

                res.append(list(range(int(a),i+1)))
            


        return res[::-1]


        """
        :type target: int
        :rtype: List[List[int]]
        """
```