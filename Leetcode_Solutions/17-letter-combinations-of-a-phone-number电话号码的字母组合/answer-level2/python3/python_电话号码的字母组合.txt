### 解题思路
这就是为什么学Python！
但是这种解法没有get算法题的意义，不推荐！


### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        conversion={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        if len(digits)==0:
            return [] 
        product=['']
        for k in digits:
            product=[i+j for i in product for j in conversion[k]]
        return product
```

