### 解题思路
是螺旋矩阵的反向思维

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int temp=1;
	    int[][] ans=new int[n][n];
	    int count=(n+1)/2,i=0;
	    while(i<count){
	        for(int j=i;j<=n-1-i;j++){
	            ans[i][j]=temp++;
	        }
	        for(int j=i+1;j<=n-1-i;j++){
	            ans[j][n-1-i]=temp++;
	        }
	        for(int j=n-1-(i+1);j>=i&& (n-1-i != i);j--){
	            ans[n-1-i][j]=temp++;
	        }
	        for(int j=n-1-(i+1);j>=i+1&& (n-1-i != i);j--){
	            ans[j][i]=temp++;
	        }
	        i++;
	       }
	    return ans;
    }
}
```