### 解题思路
双指针，右指针前进到abc齐全为止，中间记录每个字母最后一次出现的位置，左指针更新为其中最小的一个。

### 代码

```python3
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n, cnt, left = len(s), 0, 0
        while left <= n-3:
            right = left
            a, b, c = False, False, False
            while not (a and b and c) and right < n:
                if s[right] == "a":
                    a, last_a = True, right
                elif s[right] == "b":
                    b, last_b = True, right
                else:
                    c, last_c = True, right
                right += 1
            if a and b and c:
                ch = s[left]
                new_left = min(last_a, last_b,last_c) + 1
                cnt += (new_left-left)*(n - right + 1)
                left = new_left 
            else:
                break
        return cnt
                
                
        
```