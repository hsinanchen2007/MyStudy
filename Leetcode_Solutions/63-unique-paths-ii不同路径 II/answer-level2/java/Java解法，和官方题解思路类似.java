public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        //获取二维数组的维度
		int m = obstacleGrid.length;
		int n = obstacleGrid[0].length;
        //将输入数组的0和1置换，理由是正常的格子最少也要有一种走法，所以为0的只可能是障碍物格子。
		for(int i=0;i<obstacleGrid.length;i++){
			int[] arr = obstacleGrid[i];
			for(int j=0;j<arr.length;j++){
				if(arr[j]==0){
					arr[j] = 1;
					continue;
				}
				if(arr[j]==1){
					arr[j] = 0;
				}
			}
		}
        //最左面一列赋值，如果有障碍物，则后面的所有格子均为0(因为无法到达)
		boolean flagM = false;
		for(int i=0;i<m;i++){
			if(flagM){
				obstacleGrid[i][0] = 0;
			}
			if(obstacleGrid[i][0]==0){
				flagM = true;
			}
		}
        //最上面一行，同上处理
		boolean flagN = false;
		for(int i=0;i<n;i++){
			if(flagN){
				obstacleGrid[0][i] = 0;
			}
			if(obstacleGrid[0][i]==0){
				flagN = true;
			}
		}
        //遍历二维数组，如果为0，说明该位置为障碍物，则无需赋值，直接继续下一次循环。
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				if(obstacleGrid[i][j]==0){
					continue;
				}
				obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
			}
		}
        return obstacleGrid[m-1][n-1];
    }

加了一些注释，可以和官方题解结合来看。