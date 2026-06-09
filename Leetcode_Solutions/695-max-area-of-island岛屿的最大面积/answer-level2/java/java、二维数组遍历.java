### 解题思路
遍历每个元素，找到1就以它为原点递归遍历它周围的元素，递归返回找到的1的个数，每找到一个1，将它变为2（官方并没有限制不能更改数组本身元素），防止重复遍历；

### 代码

```java
class Solution {
    int[][] m_grid;
    public int maxAreaOfIsland(int[][] grid) {
        m_grid=grid;
        int maxArea=0;
        //  循环遍历每个元素
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(m_grid[i][j]==1){// 最开始找到的1（原点）
                    maxArea=Math.max(serachAround(i,j),maxArea);
                }
            }
        }
        return maxArea;
    }

    public int serachAround(int i, int j){
        m_grid[i][j]=2;//设为2  防止重复遍历
        int temp=1;//本身就是个1，所以初始化为1
        if(i>0 && m_grid[i-1][j]==1)
            temp+=serachAround(i-1,j);
        if(i+1<m_grid.length && m_grid[i+1][j]==1)
            temp+=serachAround(i+1,j);
        if(j>0 && m_grid[i][j-1]==1)
            temp+=serachAround(i,j-1);
        if(j+1<m_grid[0].length && m_grid[i][j+1]==1)
            temp+=serachAround(i,j+1);
        return temp;
    }
}
```