思路：根据元素的坐标可以通过计算判断出下一个元素的位置，时间复杂度 O(n)，空间复杂度 O（1）， n为矩阵元素总数，
解法：
`
public List<Integer> spiralOrder(int[][] matrix) {
         List<Integer> result = new LinkedList<>();

        if(matrix.length == 0 || matrix[0].length == 0){
            return result;
        }
        int vCenter = matrix.length % 2 == 1 ? (matrix.length + 1) / 2 : matrix.length / 2;
        int hCenter = matrix[0].length % 2 == 1 ? (matrix[0].length + 1) / 2 : matrix[0].length / 2 + 1;
        move(0,0,matrix, result, vCenter, hCenter);
        return result;
    }
    
    private void move(int x, int y, int [][] matrix, List<Integer> list, int vCenter, int hCenter){
        int hLength = matrix[0].length;
        int vLength = matrix.length;
        list.add(matrix[y][x]);
        if((y + 1) <= vCenter && y <= (x + 1) && (hLength - x - 1) > y){
            //右边移动一格
            move(x + 1, y, matrix, list, vCenter, hCenter);
        }
        if((y + 1) > vCenter && (hLength - x) >= (vLength - y) && x > (vLength - y - 1)){
            //左移动一格
            move(x - 1, y, matrix, list, vCenter, hCenter);
        }
        if((x + 1) < hCenter && (x + 1) < y && (vLength - y - 1) >= x){
            //上移动一格
            move(x, y - 1, matrix, list, vCenter, hCenter);
        }
        if((x + 1) >= hCenter && (hLength - x - 1) <= y && (hLength - x) < (vLength - y)){
            //下移动一格
            move(x, y + 1, matrix, list, vCenter, hCenter);
        }
    }
`