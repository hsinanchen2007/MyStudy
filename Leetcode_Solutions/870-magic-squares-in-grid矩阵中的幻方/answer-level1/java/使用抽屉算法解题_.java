### 解题思路
满足幻方的条件必定是中间的数字为5,周围的数字为满足 1->6->7->2->9->4->3->8->1
的这种圆环结构,5的上下左右必定是 1、9、3、7(这四个数字都只能组成两组 15)
并且5的周围的数字其实都可以跳过,这里没作实现
1.利用数组的索引语义记录索引对应的下一个数字
2.若5的下一个值满足条件,且该值的下一行对应列满足条件,顺时针
  若5的下一个值满足条件,且该值的上一行对应列满足条件,逆时针
3.总共判断6次即可(前两次已经判断过了)
### 代码

```java
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        //if(grid == null || grid.length < 3 || grid[1].length < 3)return 0;
        //由于是1~9的不同数字,那么必定是5在中间,并且其他数字满足顺时针或逆时针
        int[] check = {0,6,9,8,3,0,7,2,1,4};
        int result = 0;
        for(int i=1;i<grid.length-1;i++){
            for(int j=1;j<grid[0].length-1;j++){
                if(grid[i][j] == 5){
                    int next = grid[i][j+1];
                    switch(next){
                        case 1:
                        case 3:
                        case 7:
                        case 9:
                            if(check[next] == grid[i+1][j+1]){
                                if(each(grid,check,i+1,j+1,1))
                                    result++;
                            }else if(check[next] == grid[i-1][j+1]){
                                if(each(grid,check,i-1,j+1,-1))
                                    result++;
                            }
                    }
                    //5的后一位必定不用算    
                    j++;
                }
            }
        }
        return result;
    }

    public boolean each(int[][] grid,int[] check,int x,int y,int ward){
        int cur = grid[x][y];
        int next = check[cur];
        for(int i=y-2;y!=i;){
            if(grid[x][--y] != next)
                return false;
            cur = next;
            next = check[cur];
        }
        for(int i=x-2*ward;x!=i;){
            if(grid[x-=ward][y] != next)
                return false;
            cur = next;
            next = check[cur];
        }
        for(int i=y+2;y!=i;){
            if(grid[x][++y] != next)
                return false;
            cur = next;
            next = check[cur];
        }
        return true;       
    }
}
```