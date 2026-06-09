### 解题思路
97%

### 代码

```python
phone = {"2":["a", "b", "c"], "3":["d", "e", "f"], "4":["g", "h", "i"],
                "5":["j", "k", "l"], "6":["m", "n", "o"], "7":["p", "q", "r", "s"],
                "8":["t", "u", "v"], "9":["w", "x", "y", "z"]}
def generate(listA, key):
    listB = []
    if not listA:
        for char in phone[key]:
            listB.append(char)
    for i in listA:
        for char in phone[key]:
            listB.append(i+char)
    return listB
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        for i in digits:
            if i in phone:
                res = generate(res, i)
        return res
                    
```