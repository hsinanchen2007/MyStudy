```
/**
     *
     * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
     * .....3 5 7 9
     * .....2 3 4 5
     * .....java实现螺旋遍历 0ms
     * 三个标志
     * count代表循环的次数就是上下左右一共要遍历多少遍
     * val代表此时的方向0右1下2左3上
     * y代表当前的圈数0代表最外层1代表里面一层以此类推
     * .....
     * .....
     * */
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list =new ArrayList<>();
        if(matrix.length <= 0) return list;
        int m = matrix.length,n=matrix[0].length;
        int count = Math.min(m,n) * 2;
        for(int i = 0; i < count; i++){
            int val = i % 4;
            int y = i / 4;
            switch (val){
                case 0:
                    for(int j = y; j < matrix[y].length - y; j++){
                        list.add(matrix[y][j]);
                    }
                    break;
                case 1:
                    for(int j = y + 1; j < matrix.length - y; j++){
                        list.add(matrix[j][matrix[y].length - 1 - y]);
                    }
                    break;
                case 2:
                    for(int j = matrix[y].length - y - 2; j >= y; j--){
                        list.add(matrix[matrix.length - 1 - y][j]);
                    }
                    break;
                case 3:
                    for(int j = matrix.length - 2 - y; j > y; j--){
                        list.add(matrix[j][y]);
                    }
                    break;
                default:break;
            }
        }
        return list;
    }
```
