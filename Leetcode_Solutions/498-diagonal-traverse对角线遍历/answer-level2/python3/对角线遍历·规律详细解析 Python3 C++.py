### 解题思路：
**对角线的特征：**

我们首先先忽略对角线的方向，观察对角线的数量。
注意到
+ 关注第一行，发现第一行的每一项正好对应一条对角线。
+ 关注最后一列，发现最后一列的每一项正好对应一条对角线。
+ 前两者重复的即只有包含右上顶点的那一条，而除了那一条加起来就是全部的对角线。

所以对角线的总数为　行数 + 列数　- 1

观察对角线的方向，注意到对角线向右上或者向左下是交替进行的。

所以可以通过对对角线排序，通过序号判断向上或者向下。

我们设行数为 $Ｍ$，列数为$Ｎ$，令最左上角的为第 ０ 条对角线，最右下的为第 `Ｍ＋Ｎ－２` 条对角线。则当对角线的序号为偶数时，对角线是向右上的。称对角线为 `curve_line`。

**数据行列的特征：**

+ 在一条对角线上，行和列的序号加起来是恒定的，因为如果行 +1 了则列必定 -1。
+ 如果找到了行（或列）的起始与结束范围，列的就迎刃而解，这题就好做了。

**行的起始：**

+ 在对角线小于等于列数的时候，观察到始终是从第 ０ 行开始。
+ 超过了列数后，每超过一条，起始行数也要加一。
+ 超过后的起始即 `curve_line + 1 - Ｎ`。 
> 注意对角线是从 ０ 开始计数的，而行数是实打实的。

**行的结束：**
+ 从最后一行看，当对角线数大于等于行数时，观察到始终到第M行结束，即索引为 `M-1`。
+ 当对角线小于行数时，观察到每少一条，结束行数也 -1。
+ 对角线小于行数的结束点是 `curve_line`。

### 总思路：
+ 处理 `matrix` 为空的特殊情况
+ 计算 $Ｍ$，$Ｎ$
+ 生成新的列表
+ 按照对角线进行遍历，按照之前总结的规律添加到列表当中。

### 代码:

```py [-Python]
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0:
            return []
        M, N, result = len(matrix), len(matrix[0]), []
        for curve_line in range(M + N - 1):
            row_begin = 0 if curve_line + 1 <= N else curve_line + 1 - N
            row_end = M - 1 if curve_line + 1 >= M else curve_line
            if curve_line % 2 == 1:
                for i in range(row_begin,row_end + 1):
                    result.append(matrix[i][curve_line - i])
            else:
                for i in range(row_end,row_begin - 1,-1):
                    result.append(matrix[i][curve_line - i])
        return result
```
> 数据存在可优化的空间，为了方便理解没有改。例如row_begin和row_end可以用max()和min()函数进行改写。

```c++ [-C++]
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        int M = matrix.size();
        int N = matrix[0].size();
        vector <int> result;
        for (int curve_line = 0 ; curve_line < (M + N - 1) ; curve_line ++){
            int row_begin = curve_line + 1 <= N ? 0 : curve_line + 1 - N;
            int row_end =  curve_line + 1 >= M ? M - 1 : curve_line;
            if (curve_line % 2 == 1){
                for (int i = row_begin ; i <= row_end ; i++)
                    result.push_back(matrix[i][curve_line - i]);
            }
            else{
                for (int i = row_end ; i >= row_begin ; i--)
                    result.push_back(matrix[i][curve_line - i]);
            }
        }
        return result;
    };
};
```