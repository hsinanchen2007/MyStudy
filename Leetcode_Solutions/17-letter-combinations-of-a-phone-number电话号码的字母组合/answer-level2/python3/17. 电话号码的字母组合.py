### 解题思路
此处撰写解题思路
此题想到使用递推的方法
### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        word = {
            "2":["a","b","c"],
            "3":["d","e","f"],
            "4":["g","h","i"],
            "5":["j","k","l"],
            "6":["m","n","o"],
            "7":["p","q","r","s"],
            "8":["t","u","v",],
            "9":["w","x","y","z"]
        }
        if digits == "":
            return []
        ans = [""]

        for i in digits:
            ans = [a+b for a in ans for b in word[i]]
        return ans


```