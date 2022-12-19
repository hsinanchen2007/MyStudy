
![image.png](https://pic.leetcode-cn.com/d07d6599906ef3e5eb075b54f322e0daec3e95d9188b2d0380310348574d4606-image.png)

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        last = 0
        result = []
        key1 = -1
        frequency = 1
        s = S
        for i in s:
            if i != last:
                result.append(i)
                key1 =key1 +2
                result.append(1)
                frequency = 1
            elif i == last :
                frequency +=1
                result[key1] = frequency
            last = i
        if len(result)<len(s):
            res = ''
            for i in result:
                res = ('%s%s'%(res,i)) 
            return str(res)
        else:
            return s
        
```