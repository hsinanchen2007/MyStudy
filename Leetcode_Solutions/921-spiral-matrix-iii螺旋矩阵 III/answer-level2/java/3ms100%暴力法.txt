### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int [][] ret=new int[R*C][2];
        int index=1;
        ret[0][0]=r0;
        ret[0][1]=c0;
        int move=0;
        while (index<R*C){
            ++move;
            for (int i=1;i<=move;i++){
                ++c0;
                if (c0<C && c0>=0 && r0<R && r0>=0){
                    ret[index][0]=r0;
                    ret[index++][1]=c0;
                }
            }
            for (int i=1;i<=move;++i) {
                ++r0;
                if (c0 < C && c0 >= 0 && r0 < R && r0 >= 0) {
                    ret[index][0] = r0;
                    ret[index++][1] = c0;
                }
            }
            ++move;
            for (int i=1;i<=move;i++) {
                --c0;
                if (c0 < C && c0 >= 0 && r0 < R && r0 >= 0) {
                    ret[index][0] = r0;
                    ret[index++][1] = c0;
                }
            }
            for (int i=1;i<=move;i++) {
                --r0;
                if (c0<C && c0>=0 && r0<R && r0>=0){
                    ret[index][0]=r0;
                    ret[index++][1]=c0;
                }
            }
        }
        return ret;
    }
}
```