#执行用时 : 48 ms, 在所有Python3提交中击败了90.58%的用户
#内存消耗 :12.8 MB, 在所有Python3提交中击败了98.70%的用户
```
class Solution:
    def convertToTitle(self, n: int) -> str:
        if n<=0:
            return None
        numA=ord("A")
        if n<=26:
            return chr(numA+n-1)
        else:
            return self.convertToTitle((n-1)//26)+chr(numA+(n-1)%26)
```