var findNumberIn2DArray = function(matrix, target) {
    //边界条件判断
    if(matrix.length == 0) return false;
    //主要思路，从右上脚查找比较
    var rows = matrix.length;
    var cols = matrix[0].length;
    //开始比较
    row = 0;
    col = cols - 1;
    while(col >= 0 && row <rows) {
        if(matrix[row][col] > target) {
            col--;
        } else if(matrix[row][col] < target) {
            row++;
        } else {
            return true;
        }
    }
    return false;
};