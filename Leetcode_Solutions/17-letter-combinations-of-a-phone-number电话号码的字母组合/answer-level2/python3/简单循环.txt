### 解题思路
### 解题思路
思路为：把输入的字符串拆成数字，每来一个数字，在原来字符串上增加可能的结果。
例如： 输如为 "23", res表示结果
1. 初始 res = [""]
2. 来 "2", 可以代表 a, b, c,则在res每个元素上加入每个新字符，得res=['a', 'b', 'c']
3. 来 "3", 可以代表 d, e, f,则在res每个元素上加入每个新字符，得res=['a'+'d', 'a'+'e', 'a'+'f', 'b'+'d', ...]
则得到最终结果。

### 关键代码
关键代码就是 3 层 for 循环
```python3
for d in digits:
    res = [s+c for s in res for c in D[d]]
```

### 完整代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":  # 输入为空字符串，返回 [] 
            return []

        #
        D = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno',
        '7':'pqrs', '8':'tuv', '9':'wxyz'}
        
        res = [""]
        for d in digits:
            res = [s+c for s in res for c in D[d]]

        return res
```