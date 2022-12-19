思路:先创建行和列的辅助数组,遍历原数组,将为1的坐标对应的辅助数组中加1,最后再遍历一遍原数组,若为1则检查对应的坐标在辅助数组中是否大于1,若为1则说明该行或该列只有这一台,大于1则满足要求
![_@E1L{6EK_M~RKR}J446BV1.png](https://pic.leetcode-cn.com/f0a8978caa03aeffbee033c0b82528958d5186f503a43784549b1a61ec63faa7-_@E1L%7B6EK_M~RKR%7DJ446BV1.png)
```
class Solution {
    public int countServers(int[][] grid) {
        int[] helperx=new int[grid.length];
        int[] helpery=new int[grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    helperx[i]++;
                    helpery[j]++;
                }
            }
        }
        int ans=0;
         for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                  if(helperx[i]>1 || helpery[j]>1){
                      ans++;
                  }
                }
            }
        }
        return ans;
    }
}
```
