```java []
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] row = init(grid,true);
        int[] col = init(grid,false);
        //System.out.println(Arrays.toString(row));
        //System.out.println(Arrays.toString(col));
        int result = 0;
        //以当前元素为中心，当前元素的高度调整取Math.min(该行元素最大值，该列元素最大值)
        //累加每个元素调整后的差值为最终答案。
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                result+=Math.min(row[i],col[j])-grid[i][j];
            }
        }
        return result;
    }
    //找出每行或每列最大元素保存在数组里， sign：true-行
    public int[] init(int[][] grid,boolean sign){
        int[] result = new int[grid.length];
            for(int i = 0;i<grid.length;i++){
                int max = 0;
                if(sign){
                    max = grid[i][0];
                }else{
                    max = grid[0][i];                    
                }
                for(int j =0;j<grid[0].length;j++){
                    if(sign){
                        max = Math.max(grid[i][j],max);                        
                    }else{
                        max = Math.max(grid[j][i],max);                        
                    }
                }
                result[i] = max;
            }            

        return result;
    }
}
```

