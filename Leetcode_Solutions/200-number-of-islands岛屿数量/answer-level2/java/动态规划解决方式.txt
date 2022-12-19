### 解题思路
1.其实是对每一行进行判断
  如果上左都有岛屿:
    1.上左岛屿不在同一个岛屿群中 : dp[j]!=0 && dp[j-1]!=0 && dp[j] != dp[j-1],跟新当前岛屿为岛屿数最少的一个,同时减少岛屿数的总和 max--
    2.上左都不为岛屿 : dp[j]==0 && dp[j-1]==0
        2条件的存在意义就在于如果都不为岛屿那么我任何新的这一个点"在现阶段"为新的岛屿，更新岛屿数量
         这里可能会觉得有问题,如果上左没有下右有的话呢？如果存在岛屿相连接那么必然会进行1的操作
    3.上或者左有一块岛屿 : 跟新当前岛屿数为不为"0"的数就行了 
        当一行循环结束需要对该行进行统一:    
        for(int k=length1-2;k>=0;k--){
                if(dp[k]!=0 && dp[k+1]!=0){
                    dp[k] = dp[k+1];
                }
            }


### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        int length = grid.length;
        if(length == 0|| grid[0].length == 0){
            return 0;
        }
        int length1 = grid[0].length;
        int[] dp = new int[length1];
        int[] flag = new int[length1 * length];
        int index = 1;//代表发生过的岛屿数量(即使合并也不会减少该值),主要用作更新岛屿count值
        int count = grid[0][0]-48;
        dp[0] = count;
        for(int i=1;i<length1;i++){
            if(grid[0][i] == '1'){
                if(grid[0][i-1] == '0'){
                    dp[i] = ++count;
                    flag[count] = 1;
                }else{
                    dp[i] = dp[i-1];
                }  
            }
        }
        index = count;
        for(int i=1;i<length;i++){
            for(int j=0;j<=length1-1;j++){
                if(grid[i][j] == '1'){
                    if(j == 0){
                        if(grid[i-1][j] == '0'){
                            count++;
                            dp[j] = ++index;
                            flag[index] = 1;
                        }
                    }else{
                        int index1 = Math.max(dp[j],dp[j-1]);
                        if(dp[j]!=0 && dp[j-1]!=0 && dp[j] != dp[j-1]){
                            if(flag[index1] == 1){
                            flag[index1] = 0;
                            count--;
                        }
                            dp[j] = Math.min(dp[j],dp[j-1]);
                        }else if(dp[j]==0 && dp[j-1]==0){
                            count++;
                            dp[j] = ++index;
                            flag[index] = 1;
                        }else{
                            dp[j] = index1;
                        }
                    }
                }else{
                    dp[j] = 0;
                }
            }
            for(int k=length1-2;k>=0;k--){
                if(dp[k]!=0 && dp[k+1]!=0){
                    dp[k] = dp[k+1];
                }
            }
        }
        return max;
    }
}
```