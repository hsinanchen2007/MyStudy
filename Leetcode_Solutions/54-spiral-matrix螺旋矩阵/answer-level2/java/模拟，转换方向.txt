### 解题思路
利用模拟的方法
每次碰到越界或者visited过的数字，就直接转换方向，因为设定了总共遍历的次数，不用担心最后遍历的越界
转换方向有两个int数组，1,0，-1,0
                     0，1,0，-1

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int row=matrix.length;
        List<Integer> res=new ArrayList<>();
        if(row==0)
            return res;
        int column=matrix[0].length;

        

        boolean[][] visited=new boolean[row][column];
        int[] dir_row={0,1,0,-1};
        int[] dir_col={1,0,-1,0};
        int dir_count=0;
        int r=0,c=0;
        for (int i=0;i<row*column;i++)
        {
            visited[r][c]=true;
            res.add(matrix[r][c]);
            int temp_row=r+dir_row[dir_count];
            int temp_col=c+dir_col[dir_count];
            if (temp_row>=row || temp_col>=column || temp_row<0||temp_col<0||visited[temp_row][temp_col])
            {
                dir_count=(dir_count+1)%4;
                r=r+dir_row[dir_count];
                c=c+dir_col[dir_count];
            }
            else
            {
                r=temp_row;
                c=temp_col;
            }
        }
        return res;
    }
}

```