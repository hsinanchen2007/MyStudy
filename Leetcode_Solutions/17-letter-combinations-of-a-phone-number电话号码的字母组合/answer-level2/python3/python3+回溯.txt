### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        hashmap = {"2":["a","b","c"],"3":["d","e","f"],"4":["g","h","i"],"5":["j","k","l"],
                   "6":["m","n","o"],"7":["p","q","r","s"],"8":["t","u","v"],"9":["w","x","y","z"]}
        
        if not digits:
            return []
        result = []

        def backtrack(digit, track):
            if len(digit)==1:
                for i in hashmap[digit[0]]:
                    result.append(track+i)
                return
            for i in hashmap[digit[0]]:
                backtrack(digit[1:], track+i)
        
        backtrack(digits,'')
        return result

```