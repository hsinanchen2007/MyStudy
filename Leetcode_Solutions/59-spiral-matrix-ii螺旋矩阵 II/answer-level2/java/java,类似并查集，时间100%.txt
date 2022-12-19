首先想到的是是不是有递推公式那样遍历一遍数组就行了，研究了五分钟。。。果然没有
那就模拟这个过程，到达边界转向就行了。



```
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
37.9 MB
, 在所有 Java 提交中击败了
5.00%
的用户
```



```
class Solution {
    int[][] res;
    int nox=1,max;
    public int[][] generateMatrix(int n) {
        res=new int[n][n];
        max=n*n;
        plus_D(0, 0);
        return res;
    }
    void plus_R(int x,int y){
        if (max>=nox)
            if (x<res.length&&res[x][y]==0)
            {
                res[x][y]=nox++;
                plus_R(x+1, y);
            }
            else plus_D(x-1,y+1);
    }
    void plus_L(int x,int y){
        if (max>=nox)
            if (x>=0&&res[x][y]==0)
            {
                res[x][y]=nox++;
                plus_L(x-1, y);
            }
            else plus_U(x+1,y-1);
    }
    void plus_U(int x,int y){
        if (max>=nox)
            if (y>=0&&res[x][y]==0)
            {
                res[x][y]=nox++;
                plus_U(x, y-1);
            }
            else plus_R(x+1,y+1);
    }
    void plus_D(int x,int y){
        if (max>=nox)
            if (y<res[0].length&&res[x][y]==0)
            {
                res[x][y]=nox++;
                plus_D(x, y+1);
            }
            else plus_L(x-1,y-1);
    }
}
```
