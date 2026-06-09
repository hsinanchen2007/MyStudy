### 解题思路
递归的方式，从后往前。只有两种方式到达起点。
### 代码

```java
class Solution {
    int c;
    int r;
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        c = obstacleGrid[0].length - 1;
        r = obstacleGrid.length - 1;
        if(obstacleGrid[r][c] == 1 || obstacleGrid[0][0] == 1){
            return new ArrayList<>();
        }
        List<List<Integer>> res = new ArrayList<>();
       boolean flag = solution(c,r,obstacleGrid,res);
        if(flag){
        addElement(r,c,res);
        }
        return res;
    }

    private boolean solution(int col,int row,int[][] nums,List<List<Integer>> res){
        if(row < 0 || col < 0 ){
            return false;
        }else if(nums[row][col] == 1){
            return false;
        }else if(row == 0 && col == 0){
            return true;
        }
        // 开始递归
        boolean flag = solution(col,row-1,nums,res);
        if(flag){
            addElement(row-1,col,res);
            return true;
        }
        boolean flag1 = solution(col-1,row,nums,res);
        if(flag1){
            addElement(row,col-1,res);
            return true;
        }
        return false;
    }

    private void addElement(int row,int col,List<List<Integer>>  res){
            List<Integer> list = new ArrayList<>();
            list.add(row);
            list.add(col);
            res.add(list);
    }
}
```