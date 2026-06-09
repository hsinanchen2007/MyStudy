### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        dic = collections.defaultdict(int)
        for  domin in cpdomains:
            num, second = domin.split(' ')
            parts = second.split(".")
            temp = parts[-1]
            dic[temp]+=int(num)
            for i in range(len(parts)-2,-1,-1):
                temp= parts[i]+'.'+temp
                dic[temp] +=int(num)

        return [str(dic[key])+" "+key  for key in dic]
```