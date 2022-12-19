/*解题思想：动态规划。自上而下。
解题步骤如下：
1、确定状态：
   二维数组定义为：A[m][n]，m和n代表行数和列数，在实际取用元素时要从[0][0]->[m-1][n-1]
   从左上到右下路径上的数字加和的最小值记为：F[i,j],此处i = m-1，j = n -1，F[i,j]
   因每次只能向下或者向右移动1步，所以对于二维数组A[m][n]来说，其最优解为：F[i,j] = Min(F[i-1,j],F[i,j-1]) + A[i][j] // 此处i<m,j<n
2、转移方程：F[i,j] = Min(F[i-1,n],F[i,j-1]) + A[i][j],此处：0<i<m && 0<j<n
3、初始条件和边界情况:
   a、i = 0  && j = 0  => F[1,1] = A[0][0]           
   b、i = 0  && j != 1 => F[1,j] = F[1,j-1] + A[0][j-1]
   c、j != 1 && j = 0  => F[i,1] = F[i-1,1] + A[i-1][0]
4、计算顺序：从A[0][0]开始直到A[m-1][n-1]
5、这个题目貌似是最简单的

注意：
1、F[i,j]代表最小值，而不是一个表达式，所以在实际实现的时候直接取用这里面的值即可
2、F[i,j]的值存储在输入二位数组grid中，这样空间复杂度就是O(1)
3、因为要遍历整个二维数组，所以时间复杂度为O(m*n)
*/
/*
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int rowcnt = gridSize;
    int *cloumcnt = gridColSize;
    int i,j;
    
    if(rowcnt <= 0){
        return 0;
    }
    
    for(i = 0;i < rowcnt;i++){
        if(cloumcnt <= 0 )
            return 0;
    }
    
    for(i = 0;i < rowcnt;i++){
        for(j = 0;j < cloumcnt[i];j++){
            if(i == 0 && j == 0){//第一个边界条件
                continue;
            }else if(i == 0 && j > 0){//第二个边界条件
                grid[i][j] = grid[i][j-1] + grid[i][j];
            }else if(i > 0 && j == 0){//第三个边界条件
                grid[i][j] = grid[i-1][j] + grid[i][j];
            }else{//通用状态转移方程            
                grid[i][j] += (grid[i][j-1] <= grid[i-1][j]) ? grid[i][j-1] : grid[i-1][j];
            }
        }
    }
    
    return grid[rowcnt -1][cloumcnt[rowcnt - 1] - 1];
}
*/
/*************************************************************************************************************/
/*下面使用递归的方式进行求解，自下而上。

第二种解法：迭代法，自下而上进行迭代
	
	解题思想：自下而上的迭代法
数组：A[m][n]
解题步骤：
1、递归公式：F[i,j] = Min(F[i-1,n],F[i,j-1]) + A[i][j]
2、递归的边界条件：
i=0&&j=0 => A[0][0]
i=0    	 => F[0,j] = F[0,j-1]) + A[0][j]
j=0      => F[i,0] = F[i-1,0]) + A[j][0]
3、降低时间复杂度和空间负责度的方法：
   a、初始化一个和原数组一样大的二维数组record[][]记录每一个元素对应的最短路径
   b、每一次计算，将F[i,j]对应的结果存储在新开的数组的[i][j]处
   c、每一次计算前，都检查record[i][j]是否计算过，如果计算过则直接返回record[i][j]即可
4、计算顺序：从A[m-1][n-1]开始迭代到A[0][0]结束迭代。
![20191024-213858(eSpace).png](https://pic.leetcode-cn.com/5ba9f46b759d8551d687ffc8d4db5527db5fd15b30a1cd9e9bf9322eb36e9b18-20191024-213858\(eSpace\).png)

注意：
1、F[i,j]代表最小值，而不是一个表达式，所以在实际实现的时候直接取用这里面的值即可
2、F[i,j]的值存储在输入二位数组record中，空间复杂度就是O(m*n)
3、因为要遍历整个二维数组，所以时间复杂度大于O(m*n)  
*/

int **record;//作用是保存已经计算过的结果，降低时间和空间复杂度,否则会超出时间限制

int minSum(int **array,int i,int j){
    int res;
    int minSum1;
    int minSum2;
    
    if(i == 0 && j == 0){
        return array[i][j];
    }
    
    if(record[i][j] > 0){
        return record[i][j];
    }
    if(i == 0){
        return array[i][j] + minSum(array,i,j-1);
    }
    
    if(j == 0){
        return array[i][j] + minSum(array,i-1,j);
    }
    
    minSum1 = minSum(array,i-1,j);
    minSum2 = minSum(array,i,j-1);
    
    res = array[i][j] + ((minSum1 < minSum2) ? minSum1 : minSum2);//此处一定要将3目表达式用括弧括起来，否则会由于优先级的问题导致返回值出错。。。
    record[i][j] = res;
    return res;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i,j;
    
    if(gridSize <= 0){
        return 0;
    }
    
    for(i = 0;i < gridSize;i++){
        if(gridColSize[i] <= 0){
            return 0;
        }
    }
    
    record = (int **)malloc(gridSize * sizeof(int *));
    for(i = 0;i < gridSize;i++){
        record[i] = (int *)malloc(gridColSize[i] * sizeof(int));
    }
    
    for(i = 0;i < gridSize;i++){
        for(j = 0;j < gridColSize[i];j++){
            record[i][j] = 0;
        }
    }
    
    int result = minSum(grid,gridSize - 1,gridColSize[0] - 1);
    
    return result;
}