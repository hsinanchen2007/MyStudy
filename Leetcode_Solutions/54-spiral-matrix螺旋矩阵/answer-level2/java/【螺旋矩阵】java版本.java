### 解题思路
1、螺旋相当于向4个不同方向进行遍历，按顺序即向右，向下，向左，向上遍历
2、记录x（行），y（列）的最大最小值，按顺序遍历有依次改变这些值，向右（xMin++），向下（yMax--），向左（xMax--），向上（yMin++）
3、当元素全部遍历完后，跳出循环，避免遍历到最后一行或列时被添加重复数据

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix == null) return null;
        ArrayList<Integer> array = new ArrayList<>();
        if (matrix.length == 0) return array;
        int size = matrix.length * matrix[0].length;
        //记录x，y的最大最小值
        int xMin = 0;
        int xMax = matrix.length - 1;
        int yMin = 0;
        int yMax = matrix[0].length - 1;
        while (xMin <= xMax && yMin <= yMax) {
            //向右遍历
            for (int y = yMin; y <= yMax; y++) array.add(matrix[xMin][y]);
            //当全部元素遍历完后，跳出循环
            if (array.size() == size) break;
            xMin++;

            //向下遍历
            for (int x = xMin; x <= xMax; x++) array.add(matrix[x][yMax]);
            //当全部元素遍历完后，跳出循环
            if (array.size() == size) break;
            yMax--;

            //向左遍历
            for (int y = yMax; y >= yMin; y--) array.add(matrix[xMax][y]);
            //当全部元素遍历完后，跳出循环
            if (array.size() == size) break;
            xMax--;

            //向右遍历
            for (int x = xMax; x >= xMin; x--) array.add(matrix[x][yMin]);
            //当全部元素遍历完后，跳出循环
            if (array.size() == size) break;
            yMin++;
        }
        return array;
    }
}
```