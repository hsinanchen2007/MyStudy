### 解题思路
当两字符串a,b首位不同时，有三种操作： 1.字符串a增加一位与b[0]相同的字符，然后计算修改后的a'[1:]（即原始的a[0:]）与b[1:]的编辑距离后加一。 2.字符串a删除头一位a[0]，然后计算a'[0:]与b[0:]的编辑距离加一，3.字符串a第一位变为与b[0]相同的字符，然后计算a'[1:]与b[1:]的编辑距离后加一。

当任意一方为空时，编辑距离为另一方的长度（另一方删除其长度个数的字符）

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        self.dp = {}
        res = self.solve(word1,word2)
        return res

    def solve(self, a, b):
        key = (a,b)
        if key in self.dp:
            return self.dp[key]
        if not a and not b:
            res= 0
        elif not a:
            res= len(b)
        elif not b:
            res= len(a)
        elif a[0] == b[0]:
            res= self.solve(a[1:],b[1:])

        else:
            add_change = self.solve(a,b[1:])+1
            del_change = self.solve(a[1:],b)+1
            switch_change = self.solve(a[1:],b[1:])+1

            res= min([add_change,del_change,switch_change])
        self.dp[key] = res
        return res

```