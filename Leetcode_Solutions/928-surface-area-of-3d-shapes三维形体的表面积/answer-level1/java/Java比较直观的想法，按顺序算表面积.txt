### 解题思路
1、俯视图的表面积最容易算出
2、按行从左往右按顺序遍历，当前立方体的高度比左边低，则加上低的那部分，比右边的低，则加上低的那部分
3、同理，按列，从前往后遍历下

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        if(grid==null || grid.length<1) return 0;
        int row = grid.length;
        if(grid[0].length<1) return 0;
        int col = grid[0].length;
        int area1 = 0;//俯视图的面积
        int area2 = 0;//从左向右扫描的面积
        int area3 = 0;//从前向后扫描的面积
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0){//俯视图
                    area1++;
                }
            }
        }
        //从左向右扫描
        for(int i=0;i<row;i++){
            area2 = area2+getArea(grid[i]);
        }
        //从前向后扫描
        for(int j=0;j<col;j++){
            int[] temp = new int[row];
            for(int i=0;i<row;i++){
                temp[i] = grid[i][j];
            }
            area3 = area3+getArea(temp);
        }
        return area1*2+area2+area3;
    }

    public int getArea(int[] nums){
        int res = 0;
        int len = nums.length;
        for(int i=0;i<len;i++){
            if(i+1<len && nums[i+1]>nums[i]){
                res = res+nums[i+1]-nums[i];
            }
            if(i-1>=0 && nums[i-1]>nums[i]){
                res = res+nums[i-1]-nums[i];
            }
        }
        return res+nums[0]+nums[len-1];
    }
}
```