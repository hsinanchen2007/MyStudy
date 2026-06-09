## 解析
旋转类题目的关键在于首先需要确定定点。
     本题可选择左上角和右下角两个定点。然后按照规律进行旋转。
     旋转一圈以后。左上角横纵坐标都+1。右下角横纵坐标都减1.
     最后还需要考虑只剩下一行或者一列的情况。
## 代码
````java
public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        if (matrix == null || matrix.length == 0) {
            return list;
        }

        int startx = 0;
        int starty = 0;
        int endx = matrix.length-1;
        int endy = matrix[0].length-1;
        while (startx < endx && starty < endy) {
            for (int i = starty; i < endy ; i++) {
                list.add(matrix[startx][i]);
            }
            for (int i = startx; i < endx ; i++) {
                list.add(matrix[i][endy]);

            }
            for (int i = endy; i > starty; i--) {
                list.add(matrix[endx][i]);

            }
            for (int i = endx ; i > startx; i--) {
                list.add(matrix[i][starty]);
            }
            startx++;
            endx--;
            starty++;
            endy--;
        }
        //只有一行时
        if(starty == endy){
            while (startx <= endx) {
                list.add(matrix[startx++][starty]);
            }
        }else {
            //只有一列时
            if(startx == endx){
                while (starty <= endy) {
                    list.add(matrix[startx][starty++]);
                }

            }

        }
        return list;
    }
````