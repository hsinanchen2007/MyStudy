### 解题思路
统计每种元素个数
计算最大公约数

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        #判断是否无重复元素
        if len(set(deck)) == len(deck):
            return False
        
        #统计每种元素个数
        dic = {}
        ans = []
        for i in deck:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        for m in dic:
            ans.append(dic[m])
        
        #计算元素个数的最大公约数
        gys = ans[0]
        for j in range(1, len(ans)):
            gys = math.gcd(gys, ans[j])
        if gys == 1:
            return False
        return True
```