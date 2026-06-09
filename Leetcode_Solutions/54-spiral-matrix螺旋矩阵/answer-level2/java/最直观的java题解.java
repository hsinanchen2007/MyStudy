最容易看懂的写法。看懂一个for循环就够了
每遍历完一行/一列后，将这一行/一列删除（以移动边界的方式）
```
/**
     * 给出上下左右四个边界
     * 遍历上方，则up++;
     * 遍历右方，则right--;
     * 遍历下方，则down--;
     * 遍历左方，则left++;
     * 终止条件：返回值的长度与元素总数相等
     */
    public List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> result = new ArrayList<>();
        if (matrix==null || matrix.length==0) return result;
        int rowNum = matrix.length;
        int colNum = matrix[0].length;
        int up = 0;
        int left = 0;
        int right = colNum-1;
        int down = rowNum-1;
        while (true){
//——————————————————1.从左(left)至右(right)遍历第up行数据——————————————————————
            for (int col = left; col <= right; col++) {
                result.add(matrix[up][col]);
            }
            if (result.size()==colNum*rowNum) return result;
            up++;

//——————————————————2.从上(up)至下(down)遍历第right列数据——————————————————
            for (int row = up; row <= down; row++) {
                result.add(matrix[row][right]);
            }
            if (result.size()==colNum*rowNum) return result;
            right--;

//——————————————————3.从右(right)至左(left)遍历第down行数据——————————————————
            for (int col = right; col >= left; col--) {
                result.add(matrix[down][col]);
            }
             if (result.size()==colNum*rowNum) return result;
            down--;

//——————————————————4.从下(down)至上(up)遍历第left列数据——————————————————
            for (int row =down; row >= up; row--) {
                result.add(matrix[row][left]);
            }
            if (result.size()==colNum*rowNum) return result;
            left++;
        }
    }
```

