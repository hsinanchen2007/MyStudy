### 解题思路
![image.png](https://pic.leetcode-cn.com/9b8a40bd81366a0e74c19ee16012689902a5d2cb62ac5fa38ce9b8bdab2dbf5d-image.png)
没想到这么快，其实就是找所有元素个数的最大公约数

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def hcf(x, y):
            if x > y:
                smaller = y
            else:
                smaller = x   
            for i in range(1,smaller + 1):
                if((x % i == 0) and (y % i == 0)):
                    hcf = i
            return hcf

        from collections import Counter
        d_c = Counter(deck)
        temp = []
        for i in d_c:
            if d_c[i]==1:
                return False
            if d_c[i] not in temp:
                temp.append(d_c[i])
        if len(temp) == 1:
            return True
        else :
            s_t = sorted(temp)
            cf = hcf(temp[0],temp[1])
            if cf == 1:
                return False
            for k in range(2,len(temp)):
                if hcf(cf,temp[k]) == 1 :
                    return False
        return True
        

        
```