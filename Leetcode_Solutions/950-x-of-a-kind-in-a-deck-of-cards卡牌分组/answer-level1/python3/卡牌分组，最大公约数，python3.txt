### 解题思路
我们先用字典记录输入数组中每个数字出现的次数
如果存在出现次数小于`2`的数字，依照题意，可直接返回`False`
我们在所有数字出现的次数存入一个列表`temp`中，那么此时从`temp`中任取两个数的最大公约数都大于`2`，就可以返回`True`。
我们可以将问题简化，先将`temp`按照升序进行排序，此时问题就转化成了：
- `temp`中是否存在连续的两个数，使得两数的最大公约数小于`2`，如果存在，返回`False`，不存在，返回`True`

最大公约数使用辗转相除法
### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:

        def gcd(a, b):
            return a if not b else gcd(b, a%b)
        

        dic = collections.defaultdict(int)
        for i in deck:
            dic[i] += 1
        
        temp = []
        for k, v in dic.items():
            if v < 2:
                return False
            temp.append(v)
        temp.sort()
        for i in range(len(temp)-1):
            if gcd(temp[i+1], temp[i]) < 2:
                return False

        return True
        
            
```