### 解题思路
就是单纯的递归：
1）把1到n-1层从afrom放到ahelp柱子上
2）把第n层从afrom放到ato柱子上
3）把1到n-1层从ahelp放到ato柱子上
### 代码

```python3
class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        n = len(A)
        self.move(n,A,B,C)
    def move(self,num,afrom,ahelp,ato):
        if num ==1:
            ato.append(afrom.pop())
            return
        self.move(num-1,afrom,ato,ahelp)
        ato.append(afrom.pop())
        self.move(num-1,ahelp,afrom,ato)
        

```