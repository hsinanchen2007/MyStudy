# 写在前面：
整体思路：设定一个读数的方向选择方案，由于要求的是顺时针前从第一个元素开始读，
        故接下来读数时先向右，再依次向下左上。每读一个数之后立马将该元素标记
        为-1，表示已度过。每一个方向继续读数的标志是数组不越界且下一个数不-1。

# 代码分析：
```
ArrayList arrayList = new ArrayList();// 存放螺旋方式读取的数据
    /* 当数组为空时 */
    if (matrix.length == 0) {
        return arrayList;
    }
    int height = matrix.length;// 矩阵长
    int length = matrix[0].length;// 矩阵高
    int r = 0, c = 0;// 分别代表行和列

    /* 第一个数的处理 */
    arrayList.add(matrix[r][c]);
    matrix[r][c] = Integer.MAX_VALUE;
    System.out.println(Integer.MAX_VALUE);

    /* 第二个数及以后的数的处理 */
    while (true) {
        // 向右读数
        while (c + 1 < length && matrix[r][c + 1] != Integer.MAX_VALUE) {
            c++;
            arrayList.add(matrix[r][c]);// 将当前数放入arrayList中
            matrix[r][c] = Integer.MAX_VALUE;// 由于当前元素有度过故将它的值标记为-1，作为结束外层循环的标志
        }
        // 向下读数
        while (r + 1 < height && matrix[r + 1][c] != Integer.MAX_VALUE) {
            r++;
            arrayList.add(matrix[r][c]);
            matrix[r][c] = Integer.MAX_VALUE;
        }
        // 向左读数
        while (c - 1 >= 0 && matrix[r][c - 1] != Integer.MAX_VALUE) {
            c--;
            arrayList.add(matrix[r][c]);
            matrix[r][c] = Integer.MAX_VALUE;
        }
        // 向上读数
        while (r - 1 >= 0 && matrix[r - 1][c] != Integer.MAX_VALUE) {
            r--;
            arrayList.add(matrix[r][c]);
            matrix[r][c] = Integer.MAX_VALUE;
        }
        // 判断一轮右下左上读数之后，是否能进入下一轮从向右开始的循环，若当前元素的右边为-1，则结束外循环
        if (c + 1 >= length) {
            break;
        }
        if (matrix[r][c + 1] == Integer.MAX_VALUE) {
            break;
        }
    }
    return arrayList;
```
