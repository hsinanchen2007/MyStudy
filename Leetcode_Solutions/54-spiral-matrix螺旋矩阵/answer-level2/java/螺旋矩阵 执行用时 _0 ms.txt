执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :34.5 MB, 在所有 Java 提交中击败了63.43%的用户

思路：每一次循环可以分为四次加入list的操作，上边，右边，下边，左边，一个顺时针循环，每次操作一边结束之后我们将已经加入list的数组一边去除掉
所以设置 rowStart rowEnd表示行的开始和结束  colStart  colEnd 表示列的开始结束，count表示加入list的个数 total表示总个数

接下来举个例子
```
1，2，3
4，5，6
7，8，9

初始化rowStart=0，rowEnd=2；colStart=0，colEnd=2；
1，2，3加入了list，所以我们就把这一行删掉，更新行的开始位rowStart++（rowStart=1）    if (count>=total) break;
6，9加入list 删除右边一行，更新列结束位colEnd--（colEnd=1）  if (count>=total) break;
8，7加入list 删除下边一行，更新行结束位rowEnd--（rowEnd=1）  if (count>=total) break;
4，加入list 删除左边一列，更新列开始位colStart++（colStart=1）  if (count>=total) break;
至此一边循环结束，以此类推进行下一个循环
```

```java
public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix.length==0) return new ArrayList<>();
        if (matrix[0].length==0) return new ArrayList<>();
        int rowStart = 0;
        int rowEnd = matrix.length-1;
        int colStart = 0;
        int colEnd = matrix[0].length-1;
        List<Integer> list = new ArrayList<>();
        int count =0;
        int total = matrix.length*matrix[0].length;
        boolean flag = false;
        while (count < total){
            for (int i=colStart;i<=colEnd;i++){
                list.add(matrix[rowStart][i]);
                count++;

            }
            rowStart++;
            if (count>=total) break;
            for (int i=rowStart;i<=rowEnd;i++){
                list.add(matrix[i][colEnd]);
                count++;
                flag = true;
            }
            colEnd--;
            if (count>=total) break;
            for (int i=colEnd;i>=colStart;i--){
                list.add(matrix[rowEnd][i]);
                count++;

            }
            rowEnd--;
            if (count>=total) break;

            for (int i = rowEnd;i>=rowStart;i--){
                list.add(matrix[i][colStart]);
                count++;

            }
            colStart++;
            if (count>=total) break;

        }
        return list;
    }
```