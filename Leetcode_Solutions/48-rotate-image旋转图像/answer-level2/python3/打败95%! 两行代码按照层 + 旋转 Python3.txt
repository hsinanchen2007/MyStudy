## 思路
+ 将矩阵视为由外层向内层逐层处理
+ 在每一层中，对第一行的数逐个找对应部分交换（最后一个除外）
+ 利用Python独特的交换机制，即a,b=b,a可以直接交换，这里交换四个，即形如a,b,c,d = b,c,d,a

## 代码
```Python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        for i in range(len(matrix) // 2):
            for j in range(i,len(matrix) - i - 1):matrix[j][len(matrix) - i - 1], matrix[len(matrix) - i - 1][len(matrix)-j - 1],matrix[len(matrix)-j - 1][i],matrix[i][j]= matrix[i][j],matrix[j][len(matrix) - i - 1],matrix[len(matrix) - i - 1][len(matrix)-j - 1],matrix[len(matrix)-j - 1][i]
```
其中，i即层，j即层中第一行的一项。

## 难点
最后一行的行列索引还是需要仔细思考以避免出错。

交换可以采用增加变量tmp的形式，但是会复杂一点，现在这个代码看起来比较长，实际上内容是明确而简洁的。在实际做题的时候，可以先分行写，然后合并到一块儿。注意不能光分行就不管了！