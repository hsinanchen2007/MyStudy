### 解题思路
 以每两次扫描作为一个周期，那么一次横向和纵向扫描以后，矩阵就会进行降维，一直到维度为0就停止，所以只要区分这个周期里面的扫描是左->右，上->下组合，还是右->左，上->下组合即可。

由于使用了Math.abs内存占用会很高，优化方面可以使用一个其他变量代表1和-1，来表示方向，那么速度可以继续提升和同时内存占用会低很多。

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
            if( n <= 0 ){
		        return null;
		    }
		    int[][] output = new int[n][n];
		    int i = 0, j = 0;
		    int current = 1;
		    boolean hori = true;
		    int ori = 2;//以每两次扫描作为一个周期,其实ori和hori可以合并成一个变量
		    output[0][0]=current;
		    int count = 1;
		    int dimens = n;
		    while( dimens > 0 ){
		    	count =0;
		        int step =  ori/Math.abs( ori );//表示方向，正的就是左到右，或者上到下，负的就是右到左或者是下到上
		        if( hori ){
		            while( count < dimens ){
		                j +=step;
		                if(  i >= n || j >= n ||  output[i][j] != 0 ){
		                	j -=step;
		                	break;
		                }
		                output[i][j] = ++current;
		                count ++;
		            }
		            
		        }else{
		            while( count <dimens ){
		                i +=step;
		                if(  i >= n || j >= n || output[i][j] != 0  ){
		                	 i -=step;
		                	break;
		                }
		                output[i][j] = ++current;
		                count ++;
		            }
		        }
		        int newOri = ori - ori / Math.abs(ori);

		        if( newOri == 0 ){
		            ori = -ori/Math.abs(ori)*2;
		            --dimens;
		   
		        }else {
		            ori = newOri;
		        }
		        hori = !hori;
		    }

		return output;
    }
}
```