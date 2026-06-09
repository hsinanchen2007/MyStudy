螺旋矩阵，就是从外层顺时针遍历输出，我们看一下初始状态：
```text
[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
```

输出第一行后应该向下转向输出，刺客我们将已经输出的第一行去除，即就是
```text
[
    [4,5,6],
    [7,8,9]
]
```
我们对矩阵进行旋转得到：
```text
[
    [6,9],
    [5,8],
    [4,7]
]
```
后面继续经过输出，去除，旋转分别得到：
```text
[       
    [8,7],
    [5,4]
]
[
    [4],
    [5]
]
[
    [5]
]
```

我们来看代码
```java
public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        //判断数组是否为空
        if (matrix.length == 0){
            return result;
        }
        //求出数组的行列数
        int line = matrix[0].length;
        int row = matrix.length;
        while (true){
            //首先将第一行放入结果集中
            for (int ele : matrix[0]) {
                result.add(ele);
            }
            //去除第一行
            matrix = Arrays.copyOfRange(matrix, 1, row);
            //跳出循环条件（数组的长度为空）
            if (matrix.length == 0){
                break;
            }
            //求出新的长度
            row = matrix.length;
            line = matrix[0].length;
            //进行数组旋转（转置）
            int[][] ans = new int[line][row];
            for (int i = line - 1; i >= 0; i--) {
                for (int j = 0; j < row; j++) {
                    ans[line - 1 - i][j] = matrix[j][i];
                }
            }
            matrix = ans;
            //更新行数，为下一次循环的跳出条件做判断
            row = matrix.length;
        }
        return result;
```