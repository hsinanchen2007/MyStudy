### 解题思路
python3 28 ms击败99.78%用户。
用递归的思路，主要是判断左括号和右括号的数量：
1.左右括号数量均不能大于n；
2.右括号数量始终不能大于左括号


### 代码

```python3
class Solution:
    def calc(self, l, r, n, c, re):
        
        if r==n and l==n:
            re.append(c)
            return 
        sl = l
        sr = r
        sc = c
        if sl < n:
            self.calc(sl+1, sr, n, c+"(", re)
            if sr < sl:
                self.calc(sl, sr+1, n, c+")" ,re)
        else:
            self.calc(sl,sr+1,n, c+")",re)

    def generateParenthesis(self, n: int) -> List[str]:
        r = 0
        l = 0
        c = ""
        re = list()
        self.calc(l, r, n, c, re)
        return re





        
        
        
```