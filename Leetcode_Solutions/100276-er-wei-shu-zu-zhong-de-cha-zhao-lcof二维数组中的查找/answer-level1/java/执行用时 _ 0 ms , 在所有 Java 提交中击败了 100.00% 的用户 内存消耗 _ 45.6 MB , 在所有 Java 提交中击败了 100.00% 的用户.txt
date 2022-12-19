给定一个mxn的矩阵，找m和n的最小值min = min{m,n},则（0,0）元素的对角线元素为(0，0),(1,1),...,(min,min)
对每个对角线元素所在的行和列进行二分查找即可(每次不用对该行列的所有元素进行查找，只需要从[min,length-1]中查找)
```
public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length == 0)
            return false;
        //数组m x n
        int m = matrix.length;
        int n = matrix[0].length;
        int max;
        int min;
        max = m>n? m:n;
        min = m>n? n:m;
        boolean res = false;
        for(int i = 0;i< min;i++){
            res = binarySerch(matrix,i,i,target);
            if (res)
                break;
        }
        return res;
    }

    //对第i行和第j列元素分别进行二分查找
    public boolean binarySerch(int[][] matrix, int i, int j, int target) {
        boolean find = false;
        int left;
        int right;
        int mid;
        left = i;
        right = matrix.length - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[mid][j] == target){
                return true;
            }
            else if(matrix[mid][j] > target){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        left = j;
        right = matrix[0].length - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[i][mid] == target) {
                return true;
            }
            else if(matrix[i][mid] > target){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return find;
    }
```
