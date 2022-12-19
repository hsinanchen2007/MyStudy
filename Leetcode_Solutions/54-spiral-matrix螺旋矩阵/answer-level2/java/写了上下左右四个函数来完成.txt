### 解题思路
速度还是挺快的，100.0%，53.29%

看了别人的思路觉得自己的方法蠢哭了，但是我感觉自己的方法比较好理解，还是写一下吧

因为螺旋数组收集元素的时候一定是 向右->向下->向左->向上->向右 这个顺序的，所以我就写了上下左右四个函数
每个函数的功能逻辑都是：
在该方向上收集元素——>碰到边界（该方向收集完成）——>判断是否能向下一个方向收集——>不能：整个数组收集完成，返回/可以：转向
### 代码

```java
class Solution {
    int[][] matrix;
    int row,col;
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> Ret = new ArrayList<Integer>();
        int row = matrix.length;int col = matrix[0].length;
        if(row == 0)return Ret;
        
        this.row = row;this.col = col;this.matrix = matrix;
        int[][] collect = new int[row][col]; //用这个数组来表示某个坐标是否已经收入了Ret中
        ToRight(0,0,collect,Ret);
        return Ret;
    }
    void ToRight(int r, int c,int[][] collect,List<Integer> Ret){
        while(c < col &&  collect[r][c] == 0){  //向右收集元素 直到碰到右边界
            Ret.add(matrix[r][c]);
            collect[r][c] = 1;
            c++;
        } //向右收集元素完成
        c--;
        if(r == row-1 || collect[r+1][c] == 1){ //向右收集结束之后应该向下收集，如果这时向下碰到了边界（说明已经收集完成）
            return;//返回
        }
        else GoDown(r+1,c,collect,Ret); //否则就开始向下收集
        return;
    }
    void GoDown(int r, int c,int[][] collect,List<Integer> Ret){//下面的三个和向右的函数原理一样
        while( r < row && collect[r][c] == 0 ){
            Ret.add(matrix[r][c]);
            collect[r][c] = 1;
            r++;
        }
        r--;
        if(c == 0 || collect[r][c-1] == 1){
            return;
        }
        else ToLeft(r,c-1,collect,Ret);
        return;
    }
    void ToLeft(int r, int c,int[][] collect,List<Integer> Ret){
        while( c >=0&& collect[r][c] == 0 ){
            Ret.add(matrix[r][c]);
            collect[r][c] = 1;
            c--;
        }
        c++;
        if(r == 0 || collect[r-1][c] == 1){
            return;
        }
        else GoUp(r-1,c,collect,Ret);
        return;
    }
    void GoUp(int r, int c,int[][] collect,List<Integer> Ret){
        while( c >=0 && collect[r][c] == 0 ){
            Ret.add(matrix[r][c]);
            collect[r][c] = 1;
            r--;
        }
        r++;
        if(c == col-1 || collect[r][c+1] == 1){
            return;
        }
        else ToRight(r,c+1,collect,Ret);
        return;
    }
}
```