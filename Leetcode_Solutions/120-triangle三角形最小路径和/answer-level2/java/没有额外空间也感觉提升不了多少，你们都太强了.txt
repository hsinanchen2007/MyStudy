```
/*
	 * 自顶向下计算：边界点情况：在第一列时，经过点d(i,0)，那么必然经过点d(i-1,0),所以第一列的状态转移方程：f(i,0)=f(i-1,0)+d(i,0);
	 * 右边缘情况：经过点d(i,i)时，必然经过点d(i-1,i-1),那么右边缘的状态转移方程为：f(i,i)=f(i-1,i-1)+d(i,i);
	 * 中间情况：经过点d(i,j)时，必然经过点min(f(i-1,j-1),f(i-1,j)),那么中间点的状态转移方程为:f(i,j)=min(f(i-1,j-1),f(i-1,j))+d(i,j);
	 * 
	 * */
	//大内存情况
    public static int minimumTotal(List<ArrayList<Integer>> triangle) {
    	int row=triangle.size();
    	int[][] res=new int[row][row];
    	for(int i=0;i<row;i++)
    		for(int j=0;j<row;j++)
    			{
    			res[i][j]=0;
    			}
    	for(int i=0;i<row;i++)
    		for(int j=0;j<=i;j++)
    			res[i][j]=triangle.get(i).get(j);
    	
    	for(int i=1;i<row;i++)
    		for(int j=0;j<=i;j++){
    			if(j==0) res[i][j]=res[i-1][j]+res[i][j];
    			else if(j==i) res[i][j]=res[i-1][j-1]+res[i][j];
    			else {
    				res[i][j]=Math.min(res[i-1][j-1], res[i-1][j])+res[i][j];
    				
    			}
    		}
    	Arrays.sort(res[row-1]);
    	return res[row-1][0];
    	
        
    }
    //小内存情况
    public static int minimumTotal2(List<ArrayList<Integer>> triangle) {
    	int row=triangle.size();
    	
    	for(int i=1;i<row;i++)
    		for(int j=0;j<=i;j++){
    			if(j==0) triangle.get(i).set(j, triangle.get(i-1).get(j)+triangle.get(i).get(j));
    			else if(j==i) triangle.get(i).set(j, triangle.get(i-1).get(j-1)+triangle.get(i).get(j));
    			else{
    				triangle.get(i).set(j, Math.min(triangle.get(i-1).get(j-1), triangle.get(i-1).get(j))+triangle.get(i).get(j));
    			}
    			
    		}
    	int minValue=triangle.get(row-1).get(0);
    	for(int i=0;i<row;i++)
    		minValue=Math.min(minValue, triangle.get(row-1).get(i));
    	return minValue;
    }
```
