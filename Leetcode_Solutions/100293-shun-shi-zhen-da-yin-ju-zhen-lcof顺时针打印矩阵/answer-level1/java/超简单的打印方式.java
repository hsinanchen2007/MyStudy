### 解题思路
知乎大佬写的，看不懂来打我~~~~~~
https://zhuanlan.zhihu.com/p/103264795

### 代码

```java
class Solution {
    int[] res;
    int index=0;
    public int[] spiralOrder(int[][] matrix) {
        if(matrix==null||matrix.length==0||matrix[0].length==0){
            return new int[]{};
        }
        int x1=0;
        int y1=0;
        int x2=matrix.length-1;
        int y2=matrix[0].length-1;
        res=new int[(x2+1)*(y2+1)];
        while(x1<=x2&&y1<=y2){
            print(matrix,x1++,y1++,x2--,y2--);
        }
        return res;
    }

    public void print(int[][] matrix,int x1,int y1,int x2,int y2){
        if(x1==x2){
            for(int i=y1;i<=y2;i++){
                res[index++]=matrix[x1][i];
            }
        }else if(y1==y2){
            for(int i=x1;i<=x2;i++){
                res[index++]=matrix[i][y1];
            }
        }else{
            int curX=x1;
            int curY=y1;
            while(curY!=y2){
                res[index++]=matrix[x1][curY];
                curY++;
            }
            while(curX!=x2){
                res[index++]=matrix[curX][y2];
                curX++;
            }
            while(curY!=y1){
                res[index++]=matrix[x2][curY];
                curY--;
            }
            while(curX!=x1){
                res[index++]=matrix[curX][y1];
                curX--;
            }
        }
    }
}
```