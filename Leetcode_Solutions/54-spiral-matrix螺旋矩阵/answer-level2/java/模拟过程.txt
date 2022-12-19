## 思路:

**思路一:** 模拟过程

通过控制行的上下边界,列的左右边界

**思路二:**  旋转

直接举例子,

![Snipaste_2019-05-18_16-35-55.png](https://pic.leetcode-cn.com/00a442d0956ec5cc6d029f4cdbc4b078b09a3348c0e84bc43019523071ee741b-Snipaste_2019-05-18_16-35-55.png)


把弹出输出即可.

------


## 代码:

思路一:

python

```python [1]
class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix : return []
        shang_row = 0
        xia_row = len(matrix) - 1 
        zuo_col = 0
        you_col = len(matrix[0]) - 1
        res = []
        while shang_row <= xia_row  and  zuo_col <= you_col:
            # 从左到右
            for i in range(zuo_col, you_col+1):
                #print(shang_row, i)
                res.append(matrix[shang_row][i])
            shang_row += 1
            if shang_row > xia_row:break
            # 从上到下
            for i in range(shang_row, xia_row+1):
                res.append(matrix[i][you_col])
            you_col -= 1
            if zuo_col > you_col:break
            # 从右到左
            for i in range(you_col, zuo_col - 1,-1):
                #print(xia_row - 1, i)
                res.append(matrix[xia_row][i])
            xia_row -= 1
            # 从下到上
            for i in range(xia_row , shang_row - 1, -1):
                #print(i, zuo_col)  
                res.append(matrix[i][zuo_col])
            zuo_col += 1
        return res
```


```java [1]
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return new ArrayList<>();
        List<Integer> res = new ArrayList<>();
        int shang_row = 0;
        int xia_row = matrix.length - 1;
        int zou_col = 0;
        int you_col = matrix[0].length - 1;
        while (shang_row <= xia_row && zou_col <= you_col) {
            // 从左到右
            for (int i = zou_col; i <= you_col; i++) res.add(matrix[shang_row][i]);
            shang_row++;
            if (shang_row > xia_row) break;
            // 从上到下
            for (int i = shang_row; i <= xia_row; i++) res.add(matrix[i][you_col]);
            you_col--;
            if (zou_col > you_col) break;
            // 从右到左
            for (int i = you_col; i >= zou_col; i--) res.add(matrix[xia_row][i]);
            xia_row--;
            //从下到上
            for (int i = xia_row; i >= shang_row; i--) res.add(matrix[i][zou_col]);
            zou_col++;
        }
        return res;
    }
}
```

思路二:

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix : return []
        res = []
        while matrix:
            res.extend(matrix.pop(0))
            next_matrix = []
            #print(matrix)
            for x in zip(*matrix):
                next_matrix.append(x)
            #print(next_matrix)
            matrix = next_matrix[::-1]
        return res
```

