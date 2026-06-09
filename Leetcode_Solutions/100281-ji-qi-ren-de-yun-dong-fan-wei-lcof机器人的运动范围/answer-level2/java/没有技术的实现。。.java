### 解题思路
看了各位大佬的题解，留下了没有技术的眼泪。。。

我的想法就是遍历了，从当前节点向四周遍历，当前节点是可行的计数就+1，用递归直到走不通
递归的思路是：
    1. 判断当前节点是否满足条件，如果是，继续向右和向上递归（我想象中是个坐标系。。。）
        1. 先进行越界判断，越界就返回0
        2. 因为即使向上和向右遍历也会重复遍历，这里建了相同坐标的二维数组标记是不是已经遍历过了，遍历过的直接返回0
        3. 判断是否满足条件，不满足返回0
        4. 向右递归
        5. 向上递归
        6. 这里对当前节点做完了，当前节点满足，返回1+right+up
    2. 返回1+right+up的计数

### 代码

```java
class Solution {

 // 1. 机器人移动范围 [0,0] -[m-1,n-1]
    // 2. 机器人移动：上下左右
    // 3. 递归思路：当前位置可以，看前后左右是否可以，再继续前后左右，直至行不通，返回
    // 遍历方向：
    public int movingCount(int m, int n, int k) {
        int[][] mv = initArray(m,n);
        int count = 0;
        return movingNext(0,0,k,count,mv);
    }

    // 假设位置x,y满足
    public int movingNext(int x, int y, int k, int count, int[][] mv){

        // 越界检查
        if(x>=mv.length || y>=mv[0].length) {return 0;}

        // 检查是否已遍历
        if(checkSigned(mv,x,y)) {
            return 0;
        }

        // 标记自身
        signSelf(mv,x,y);

        if(sumPosition(x)+sumPosition(y)>k) {
            return 0;
        }

        // 右
        int right = movingNext(x+1, y, k,  count,mv);

        // 上
        int up = movingNext(x, y+1, k,count,mv);
        return 1+right+up;
    }

    public long sumPosition(int p){
        int k = 0;
        while(p/10>0){
            k+=p%10;
            p=p/10;
        }
        return k+=p;
    }

    boolean checkSigned(int[][] mv, int x, int y){
        return mv[x][y]==1;
    }

    void signSelf(int[][] mv, int x, int y){
        mv[x][y] = 1;
    }

    int[][] initArray(int m, int n){
        int[][] mv = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mv[i][j]=0;
            }
        }
        return mv;
    }

}
```