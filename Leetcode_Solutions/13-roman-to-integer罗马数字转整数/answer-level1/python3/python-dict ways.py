### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dict = {
			"I":1,
			"V":5,
			"X":10,
			"L":50,
			"C":100,
			"D":500,
			"M":1000
		}
        '''
        res = 0
        prev = 0
        for c in reversed(s):
            a = dict.get(c)
            if a<prev:
                res-=a
            else:
                res+=a
                prev=a
        return res
        '''
        ans = 0
        for i,char in enumerate(s[:-1]):
            if dict[char]>=dict[s[i+1]]:
                ans+=dict[char]
            else:
                ans-=dict[char]
        ans+=dict[s[-1]]
        return ans
        

```