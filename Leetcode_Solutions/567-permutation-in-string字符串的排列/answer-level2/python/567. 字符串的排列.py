### 解题思路
下面的代码是某位童鞋的。这题的滑动技巧是前进一位，就去掉之前第一位的记录，是我之前没有遇见到的。

### 代码

```python3
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1,l2 = len(s1), len(s2)
        if l1>l2:
            return False
        dict1 = {}
        dict2 = {}
        for ch in range(ord('a'), ord('z')+1):
            dict1[chr(ch)] = 0
            dict2[chr(ch)] = 0
        for i in range(l1):
            dict1[s1[i]] += 1
            dict2[s2[i]] += 1
        if dict1 == dict2:
            return True
        for j in range(l1, l2):
            # 增加新进的元素
            dict2[s2[j]] += 1
            # 减去之前第一位元素
            dict2[s2[j-l1]] -= 1
            if dict1 == dict2:
                return True
        return False
```