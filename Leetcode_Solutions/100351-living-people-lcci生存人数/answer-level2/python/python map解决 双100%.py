### 解题思路
map解决 双100%
map的key为年份，value为生存人数
注意map最后要按年份排序，然后返回value最大的key

### 代码

```python3
class Solution:
    def maxAliveYear(self, birth: List[int], death: List[int]) -> int:
        l_map = {}
        for i in range(len(birth)):
            for j in range(birth[i],death[i]+1):
                if j not in l_map:
                    l_map[j]=0
                l_map[j]+=1
        l_items=sorted(l_map.items(),key=lambda item:item[0])
        max_year = 1900
        max_count = 0
        for k,v in l_items:
            if v>max_count:
                max_count=v
                max_year=k
        return max_year
```