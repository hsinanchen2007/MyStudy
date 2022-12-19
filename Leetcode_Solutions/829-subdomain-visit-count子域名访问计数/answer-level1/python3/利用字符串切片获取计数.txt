### 解题思路
广泛利用str.split()。超过73.97%的用户

### 代码

```python3
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        countNet = {}
        for i in cpdomains:
            temp1, temp2 = i.split(' ')
            temp3 = temp2.split('.')
            j = len(temp3) - 2
            while j >= 0:
                temp3[j] += "." + temp3[j + 1]
                j -= 1
            for j in temp3:
                if j not in countNet:
                    countNet[j] = int(temp1)
                else:
                    countNet[j] += int(temp1)
        ret = []
        for i, j in zip(countNet.keys(), countNet.values()):
            ret.append("{} {}".format(j, i))
        return ret
```