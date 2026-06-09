### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        count_s = len(s)
        count_p = len(p)
        if count_s < count_p or count_s == count_p:
            return []
        map_p = {}
        # 遍历p
        for value in p:
            map_p[value] = map_p.get(value, 0) + 1
        res = []
        map_s = {}
        #记录一个left值，标识最左边的内容
        left = 0
        for i in range(len(s)):
            #如果不到滑动窗口，就一直加进去
            if i < count_p - 1:
                map_s[s[i]] = map_s.get(s[i], 0) + 1
                continue
                
            map_s[s[i]] = map_s.get(s[i], 0) + 1
            #比较两个是否相等
            if map_s == map_p:
               res.append(left)
            #往后移动一位，就要把窗口最左边的元素减掉
            map_s[s[left]] -= 1
            #注意map，如果这个key不存在了，要把key去掉
            if map_s[s[left]] == 0:
                map_s.pop(s[left])
                
            left += 1
        return res
```