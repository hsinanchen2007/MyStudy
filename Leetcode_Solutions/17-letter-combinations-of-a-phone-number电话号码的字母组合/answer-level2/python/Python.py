### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits)==0:
            return []
        dict={
            '2':['a','b','c'],
            '3':['d','e','f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }
        ans=[]
        def help(now,digits):
            if len(digits)==0:
                ans.append(now)
                return
            cur=digits[0]

            for i in dict[cur]:
                help(now+i,digits[1:])

        now=""

        help(now,digits)
        #print(dict)
        return ans
```