### 解题思路
思路：从an处开始计算，依次向前推进。
line3,line4:分别为1/an的分子和分母；
line5:因为从最后的分式向前计算，循环也从后向前进行；
line6:交换分子分母，实际上是将第n个分式的分母交换到第n-1个分式的分子位置上；
line7:计算第n-1个分式的分母；
line8:返回最终结果。
在传统笔算里，一般是先通分、相加，最后分子分母互换，但在程序里，顺序恰好相反。

以上为个人粗浅理解，希望得到各位的指点。
PS:题目的英文名，第一眼望过去以为是哲学
### 代码

```python3
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        numerator = 1 #分子
        denominator = cont[-1] #分母
        for i in range(len(cont)-1,0,-1):
            numerator,denominator = denominator,numerator
            denominator = cont[i-1]*numerator+denominator
        return [denominator,numerator]

```