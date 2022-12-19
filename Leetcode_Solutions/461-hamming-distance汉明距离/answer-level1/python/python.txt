
```python [class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        count=0
        while(x or y):
            if x==0:
                count+=y%2
                y/=2
            elif y==0:
                count+=x%2
                x/=2
            else:
                count+=(x%2)^(y%2)
                x/=2
                y/=2
        return count]
