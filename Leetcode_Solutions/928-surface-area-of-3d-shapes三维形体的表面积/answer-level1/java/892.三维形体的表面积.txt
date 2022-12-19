### 解题思路


### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        if(grid.length==0||grid==null){
            return 0;
        }
        int sum=0;
        int cont=6;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                int temp=cont*grid[i][j];
                sum=sum+temp;
                // System.out.println(sum+"+");//6 6+2*6=18  
                if(grid[i][j]>1){   
                    sum=sum-(grid[i][j]-1)*2;
                    // System.out.println(sum+"-");//18-1*2=16
                }
                if(j>0){
                    int mi=Math.min(grid[i][j],grid[i][j-1]);
                    sum=sum-mi*2;
                    // System.out.println(sum+"*");//16-1*2=14
                }
                if(i>0){
                    int mi=Math.min(grid[i-1][j],grid[i][j]);
                    sum=sum-mi*2;
                    // System.out.println(sum+"/");
                }
                
            }
        }
        return sum;
    }
}
```