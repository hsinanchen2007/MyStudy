### 解题思路
先建構一個字典 
再用兩層For Loop 依序逐步增加一個新的字母



### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []

        diction = collections.defaultdict(list)
        diction['2'] = ['a', 'b', 'c']
        diction['3'] = ['d', 'e', 'f']
        diction['4'] = ['g', 'h', 'i']
        diction['5'] = ['j', 'k', 'l']
        diction['6'] = ['m', 'n', 'o']
        diction['7'] = ['p', 'q', 'r', 's']
        diction['8'] = ['t', 'u', 'v']
        diction['9'] = ['w', 'x', 'y', 'z']


        idx = 0
        res = ['']
        while idx < len(digits):
            val = digits[idx]
            com = []
            for i in range(len(res)):
                for j in range(len(diction[val])):
                    com.append(res[i] + diction[val][j])
            res = com        
            idx += 1
        return res    

            
```